<?php

/**
 * @file
 * Defines migrations for the Connect country project.
 */

/**
 * Implements hook_migrate_api().
 */
function connect_country_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'geos' => array(
        'title' => t('Geo imports'),
      ),
    ),
    'migrations' => array(
      'EUCountries' => array(
        'class_name' => 'EUCountriesMigration',
        'group_name' => 'geos',
      ),
    ),
  );
  return $api;
}

/**
 * Defines a dynamic migration that is reused for each source CSV file.
 */
class EUCountriesMigration extends Migration {

  /**
   * Constructs the migration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->team = array(
      new MigrateTeamMember('Boris Doesborg', 'bdoesborg@gmail.com',
        t('Implementor')),
      new MigrateTeamMember('An Onymous', 'an@example.com',
        t('Chief Executive Migration Officer')),
    );

    $this->description = t('Update existing countries with data from CSV file.');
    $this->systemOfRecord = Migration::DESTINATION;
    $this->map = new MigrateSQLMap($this->machineName, array(
      'tid' => array(
        'type' => 'int',
        'length' => 24,
        'not null' => TRUE,
        'description' => 'TID',
      ),
    ), MigrateDestinationTerm::getKeySchema()
    );

    $this->path = drupal_get_path('module', 'connect_country') . '/data/countries.csv';

    $this->source = new MigrateSourceCSV($this->path, $this->csvcolumns(), array(

      'header_rows' => 1,
      'delimiter' => ';',
      'enclosure' => '"',
    ));

    // Creates a destination object that receives the data.
    $this->destination = new MigrateDestinationTerm('country');

    // Defines mapped source and destination fields.
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('field_country_iso_code', 'iso_code');
    $this->addFieldMapping('field_flag', 'flag');
    $this->addFieldMapping('tid', 'tid');
    $this->addFieldMapping('description', 'intro');
    $this->addUnmigratedSources(array(
      'tid',
    ));
    // Defines unmapped destination fields.
    $this->addUnmigratedDestinations(array(
      'path',
      'field_country_newsroom_origin_id',
      'field_country_type',
      'field_associated_newsroom_topic',
      'field_associated_newsroom_select',
      'weight',
      'format',
      'parent_name',
    ));
  }

  /**
   * Assigns csv column data to key.
   */
  public function csvcolumns() {
    $columns[0] = array('name', 'Name');
    $columns[7] = array('tid', 'Term ID');
    $columns[5] = array('iso_code', 'Iso Code');
    $columns[4] = array('flag', 'Flag');
    return $columns;
  }

  /**
   * Prepares rows before import.
   */
  public function prepareRow($row) {
    global $base_path;
    $row->flag = drupal_dirname(__FILE__) . '/flags/' . $row->flag;
    if (!in_array($row->iso_code, array('CN', 'IL', 'MK', 'RS', 'CH', 'TR'))) {
      $row->intro = t("Get to know all about the digital single market strategy in %name. You can find specific information on digital indicators about societal, economic and business data in your country. Details of local events and activities promoted by the Commission will be updated here.", array('%name' => $row->name));
    }
  }

}
