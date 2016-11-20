<?php
/**
 * @file
 * g2m_initiative.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function g2m_initiative_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function g2m_initiative_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function g2m_initiative_node_info() {
  $items = array(
    'g2m_initiative' => array(
      'name' => t('Go to market initiative'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
