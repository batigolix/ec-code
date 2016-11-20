<?php
/**
 * @file
 * connect_country.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function connect_country_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_country_newsroom|taxonomy_term|country|form';
  $field_group->group_name = 'group_country_newsroom';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'country';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Newsroom',
    'weight' => '6',
    'children' => array(
      0 => 'field_country_newsroom_origin_id',
      1 => 'field_associated_newsroom_topic',
      2 => 'field_associated_newsroom_select',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-country-newsroom field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_country_newsroom|taxonomy_term|country|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scoreboard_default_fields|node|score_board|form';
  $field_group->group_name = 'group_scoreboard_default_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'score_board';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Default Fields',
    'weight' => '1',
    'children' => array(
      0 => 'field_short_title',
      1 => 'field_shared_teaser',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_scoreboard_default_fields|node|score_board|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Default Fields');
  t('Newsroom');

  return $field_groups;
}
