<?php

/**
 * @file
 * Provides the pages for the Connect Country module.
 */

/**
 * Lists all the countries.
 *
 * @return array
 *   Renderable list of country taxonomy terms.
 */
function connect_country_list() {
  return _connect_country_countries();
}

/**
 * Provides content for country/%term_id/cordis.
 *
 * @param object $term
 *   Taxonomy term object.
 *
 * @return array
 *   Renderable page array.
 */
function connect_country_cordis_page($term) {
  if (module_exists('cordis_feature')) {
    $build = array();
    drupal_set_title(t('EU funded projects for !country', array('!country' => $term->name)));
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('status', 1)
      ->propertyOrderBy('created', 'DESC')
      ->entityCondition('bundle', 'project')
      ->fieldCondition('field_shared_country', 'tid', $term->tid)
      ->propertyOrderBy('sticky', 'DESC')
      ->pager(22);
    $result = $query->execute();
    if (!empty($result['node'])) {
      $build['content']['nodes'] = node_view_multiple(node_load_multiple(array_keys($result['node'])), 'teaser');
      $build['pager'] = array(
        '#markup' => theme('pager'),
        '#weight' => 10,
      );
    }
    return $build;
  }
}
