<?php

/**
 * @file
 * Defines migrations for the g2m_initiative project.
 */

/**
 * Implements hook_migrate_api().
 */
function g2m_initiative_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'g2m_initiative_migrations' => array(
        'title' => t('G2M initiative migrations'),
      ),
    ),
    'migrations' => array(
      'g2m_initiatives' => array(
        'class_name' => 'G2mInitiativeG2mInitiativeMigration',
        'group_name' => 'g2m_initiative_migrations',
      ),
    ),
  );
  return $api;
}

/**
 * Defines common elements for all g2m_initiative migrations.
 */
abstract class G2mInitiativeBaseMigration extends Migration {

  /**
   * Defines a migration group.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->issuePattern = 'https://webgate.ec.europa.eu/CITnet/jira/browse/DAE-xyz';
    $this->team = array(
      new MigrateTeamMember('Boris Doesborg', 'bdoesborg@gmail.com',
        t('Implementor')),
      new MigrateTeamMember('An Onymous', 'an@example.com',
        t('Product owner')),
    );
    $this->path = drupal_get_path('module', 'g2m_initiative') . '/data/g2m_initiatives.csv';

  }

  /**
   * Defines some defaults for a migration from CSV.
   */
  protected function sourceFileOptions() {
    return array(
      'header_rows' => 1,
      'delimiter' => ", ",
      'enclosure' => '"',
      'track_changes' => 1,
    );
  }

}


/**
 * Migrates g2m initiatives from CSV.
 */
class G2mInitiativeG2mInitiativeMigration extends G2mInitiativeBaseMigration {

  /**
   * Sets migration source, destination including fields to migrate.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import g2m');
    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'int',
        'not null' => TRUE,
      ),
    ), MigrateDestinationNode::getKeySchema()
    );
    $this->source = new MigrateSourceCSV($this->path, $this->csvcolumns(), $this->sourceFileOptions()
    );
    $this->destination = new MigrateDestinationNode('g2m_initiative', array('text_format' => 'full_html'));
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('g2m_description', 'body');
    $this->addFieldMapping('g2m_description:format')->defaultValue('basic_html');
    $this->addFieldMapping('g2m_links', 'url');
    $this->addFieldMapping('g2m_links:title', 'title');
    $this->addFieldMapping('g2m_geo_focus:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('g2m_geo_focus', 'countries')->separator(',');
    $this->addFieldMapping('g2m_topics', 'topic');
    $this->addFieldMapping('g2m_topics:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('g2m_support_types', 'services')->separator(',');
    $this->addFieldMapping('g2m_support_types:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('g2m_subtopics', 'subtopics')->separator(',');
    $this->addFieldMapping('g2m_subtopics:create_term')->defaultValue(TRUE);
    $this->addUnmigratedSources(array());
    $this->addUnmigratedDestinations(array());
  }

  /**
   * Tinkers with values before migrating.
   */
  public function prepareRow($row) {

    $row->topic = strip_tags($row->topic);

    // Massages services.
    $services = strip_tags($row->service);
    $services = explode(',', $services);
    $pretty_services = array();
    foreach ($services as $service) {

      // Uppercases the first character.
      $pretty_services[] = drupal_ucfirst(trim($service));
    }
    $row->services = implode(',', $pretty_services);

    // Massages sub topics.
    $subtopics = strip_tags($row->subtopic);
    $subtopics = explode(',', $subtopics);
    $pretty_subtopics = array();
    foreach ($subtopics as $subtopic) {

      // Uppercases the first character.
      $pretty_subtopics[] = drupal_ucfirst(trim($subtopic));
    }
    $row->subtopics = implode(',', $pretty_subtopics);

    // Massages link.
    if ($row->url == 'not yet available') {
      $row->url = NULL;
    }

    // Replaces linebreaks in description / body field.
    $row->body = nl2br($row->description);

    // Fetches the country names from the column with the country codes.
    $csv_countries = strip_tags($row->countries);

    // Replaces the EU code by the 28 country codes.
    $csv_countries = str_replace("EU", "BE,BG,CZ,DK,DE,EE,IE,EL,ES,FR,HR,IT,CY,LV,LT,LU,HU,MT,NL,AT,PL,PT,RO,SI,SK,FI,SE,UK", $csv_countries);
    $csv_countries = explode(',', $csv_countries);
    $csv_countries_by_name = array();
    $iso = array("UK", "EL");
    $estat = array("GB", "GR");
    $countries = array();
    $country_list = country_get_list();
    foreach ($csv_countries as $csv_country) {
      $csv_country = trim($csv_country);

      // Replaces estat by iso codes.
      $csv_country = str_replace($iso, $estat, $csv_country);

      // Finds the country name in the Drupal country list.
      if (array_key_exists($csv_country, $country_list)) {
        $country = $country_list[$csv_country];
        $countries[] = $country;
      }
      // Just adds the code to the list.
      else {
        $countries[] = $csv_country;
      }
    }
    $row->countries = implode(',', $countries);
  }

  /**
   * Assigns csv column data to key.
   */
  private function csvcolumns() {
    $columns[0] = array('id', 'ID');
    $columns[1] = array('title', 'Title');
    $columns[2] = array('name', 'Name of the initiative');
    $columns[3] = array('url', 'Website URL');
    $columns[4] = array('topic', 'Topic');
    $columns[5] = array('subtopic', 'Subtopic');
    $columns[6] = array('description', 'Description of initiative');
    $columns[7] = array('end_date', 'End date');
    $columns[8] = array('service', 'Service provided');
    $columns[9] = array('countries', 'Countries of partner organisations');
    return $columns;
  }

}
