<?php
/**
 * @file
 * connect_country.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function connect_country_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'eu_countries';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'EU countries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'European countries';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Field: Associated Newsroom Selection */
  $handler->display->display_options['fields']['field_associated_newsroom_select']['id'] = 'field_associated_newsroom_select';
  $handler->display->display_options['fields']['field_associated_newsroom_select']['table'] = 'field_data_field_associated_newsroom_select';
  $handler->display->display_options['fields']['field_associated_newsroom_select']['field'] = 'field_associated_newsroom_select';
  $handler->display->display_options['fields']['field_associated_newsroom_select']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Associated Newsroom Topic */
  $handler->display->display_options['fields']['field_associated_newsroom_topic']['id'] = 'field_associated_newsroom_topic';
  $handler->display->display_options['fields']['field_associated_newsroom_topic']['table'] = 'field_data_field_associated_newsroom_topic';
  $handler->display->display_options['fields']['field_associated_newsroom_topic']['field'] = 'field_associated_newsroom_topic';
  /* Field: Taxonomy term: Country Type */
  $handler->display->display_options['fields']['field_country_type']['id'] = 'field_country_type';
  $handler->display->display_options['fields']['field_country_type']['table'] = 'field_data_field_country_type';
  $handler->display->display_options['fields']['field_country_type']['field'] = 'field_country_type';
  /* Field: Taxonomy term: Flag */
  $handler->display->display_options['fields']['field_flag']['id'] = 'field_flag';
  $handler->display->display_options['fields']['field_flag']['table'] = 'field_data_field_flag';
  $handler->display->display_options['fields']['field_flag']['field'] = 'field_flag';
  $handler->display->display_options['fields']['field_flag']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_flag']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Iso Code */
  $handler->display->display_options['fields']['field_country_iso_code']['id'] = 'field_country_iso_code';
  $handler->display->display_options['fields']['field_country_iso_code']['table'] = 'field_data_field_country_iso_code';
  $handler->display->display_options['fields']['field_country_iso_code']['field'] = 'field_country_iso_code';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'country' => 'country',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/eu-countries';
  $translatables['eu_countries'] = array(
    t('Master'),
    t('European countries'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Name'),
    t('Associated Newsroom Selection'),
    t('Associated Newsroom Topic'),
    t('Country Type'),
    t('Flag'),
    t('Iso Code'),
    t('Term ID'),
    t('.'),
    t(','),
    t('Page'),
  );
  $export['eu_countries'] = $view;

  return $export;
}
