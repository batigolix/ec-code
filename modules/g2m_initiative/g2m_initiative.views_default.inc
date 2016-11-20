<?php
/**
 * @file
 * g2m_initiative.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function g2m_initiative_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'go_to_market_initiatives_2';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Go to market initiatives 2';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'EU go to market support for entrepeneurs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '22';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'g2m-item-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'g2m-item-list-wrapper';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<strong>Innovators and entrepreneurs:</strong> Use the tool below to discover EU initiatives that provide support to help you "go to market" with your innovations, products or services. Discover existing services and initiatives offering support that can address "Go to Market" needs such as: investor introductions, mentoring, business plan development, legal advice and expanding to new markets.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['g2m_description']['id'] = 'g2m_description';
  $handler->display->display_options['fields']['g2m_description']['table'] = 'field_data_g2m_description';
  $handler->display->display_options['fields']['g2m_description']['field'] = 'g2m_description';
  $handler->display->display_options['fields']['g2m_description']['label'] = '';
  $handler->display->display_options['fields']['g2m_description']['element_label_colon'] = FALSE;
  /* Field: Content: Types of support / service provided */
  $handler->display->display_options['fields']['g2m_support_types']['id'] = 'g2m_support_types';
  $handler->display->display_options['fields']['g2m_support_types']['table'] = 'field_data_g2m_support_types';
  $handler->display->display_options['fields']['g2m_support_types']['field'] = 'g2m_support_types';
  $handler->display->display_options['fields']['g2m_support_types']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['g2m_support_types']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['g2m_support_types']['delta_offset'] = '0';
  /* Field: Content: Links */
  $handler->display->display_options['fields']['g2m_links']['id'] = 'g2m_links';
  $handler->display->display_options['fields']['g2m_links']['table'] = 'field_data_g2m_links';
  $handler->display->display_options['fields']['g2m_links']['field'] = 'g2m_links';
  $handler->display->display_options['fields']['g2m_links']['label'] = '';
  $handler->display->display_options['fields']['g2m_links']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['g2m_links']['alter']['text'] = '[title] <small>website</small>';
  $handler->display->display_options['fields']['g2m_links']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['g2m_links']['alter']['path'] = '[g2m_links-url]';
  $handler->display->display_options['fields']['g2m_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['g2m_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['g2m_links']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'g2m_initiative' => 'g2m_initiative',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Types of support / service provided (g2m_support_types) */
  $handler->display->display_options['filters']['g2m_support_types_tid']['id'] = 'g2m_support_types_tid';
  $handler->display->display_options['filters']['g2m_support_types_tid']['table'] = 'field_data_g2m_support_types';
  $handler->display->display_options['filters']['g2m_support_types_tid']['field'] = 'g2m_support_types_tid';
  $handler->display->display_options['filters']['g2m_support_types_tid']['group'] = 1;
  $handler->display->display_options['filters']['g2m_support_types_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['g2m_support_types_tid']['expose']['operator_id'] = 'g2m_support_types_tid_op';
  $handler->display->display_options['filters']['g2m_support_types_tid']['expose']['label'] = 'Types of support / service provided';
  $handler->display->display_options['filters']['g2m_support_types_tid']['expose']['operator'] = 'g2m_support_types_tid_op';
  $handler->display->display_options['filters']['g2m_support_types_tid']['expose']['identifier'] = 'g2m_support_types_tid';
  $handler->display->display_options['filters']['g2m_support_types_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['g2m_support_types_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    16 => 0,
    14 => 0,
    5 => 0,
    29 => 0,
    27 => 0,
    15 => 0,
    26 => 0,
    12 => 0,
    13 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    24 => 0,
    28 => 0,
  );
  $handler->display->display_options['filters']['g2m_support_types_tid']['type'] = 'select';
  $handler->display->display_options['filters']['g2m_support_types_tid']['vocabulary'] = 'g2m_support_type';
  /* Filter criterion: Content: Sub topics / sectors (g2m_subtopics) */
  $handler->display->display_options['filters']['g2m_subtopics_tid']['id'] = 'g2m_subtopics_tid';
  $handler->display->display_options['filters']['g2m_subtopics_tid']['table'] = 'field_data_g2m_subtopics';
  $handler->display->display_options['filters']['g2m_subtopics_tid']['field'] = 'g2m_subtopics_tid';
  $handler->display->display_options['filters']['g2m_subtopics_tid']['group'] = 1;
  $handler->display->display_options['filters']['g2m_subtopics_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['g2m_subtopics_tid']['expose']['operator_id'] = 'g2m_subtopics_tid_op';
  $handler->display->display_options['filters']['g2m_subtopics_tid']['expose']['label'] = 'ICT topics';
  $handler->display->display_options['filters']['g2m_subtopics_tid']['expose']['operator'] = 'g2m_subtopics_tid_op';
  $handler->display->display_options['filters']['g2m_subtopics_tid']['expose']['identifier'] = 'g2m_subtopics_tid';
  $handler->display->display_options['filters']['g2m_subtopics_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['g2m_subtopics_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    16 => 0,
    14 => 0,
    5 => 0,
    29 => 0,
    27 => 0,
    15 => 0,
    26 => 0,
    12 => 0,
    13 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    24 => 0,
    28 => 0,
  );
  $handler->display->display_options['filters']['g2m_subtopics_tid']['type'] = 'select';
  $handler->display->display_options['filters']['g2m_subtopics_tid']['vocabulary'] = 'g2m_subtopics';
  /* Filter criterion: Content: Geographical focus (g2m_geo_focus) */
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['id'] = 'g2m_geo_focus_tid_1';
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['table'] = 'field_data_g2m_geo_focus';
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['field'] = 'g2m_geo_focus_tid';
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['expose']['operator_id'] = 'g2m_geo_focus_tid_1_op';
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['expose']['label'] = 'Geographical focus';
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['expose']['operator'] = 'g2m_geo_focus_tid_1_op';
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['expose']['identifier'] = 'g2m_geo_focus_tid_1';
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    16 => 0,
    14 => 0,
    5 => 0,
    27 => 0,
    15 => 0,
    26 => 0,
    12 => 0,
    13 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    24 => 0,
    28 => 0,
  );
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['g2m_geo_focus_tid_1']['vocabulary'] = 'g2m_geo_focus';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'go-to-market-support';
  $translatables['go_to_market_initiatives_2'] = array(
    t('Master'),
    t('EU go to market support for entrepeneurs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<strong>Innovators and entrepreneurs:</strong> Use the tool below to discover EU initiatives that provide support to help you "go to market" with your innovations, products or services. Discover existing services and initiatives offering support that can address "Go to Market" needs such as: investor introductions, mentoring, business plan development, legal advice and expanding to new markets.'),
    t('Types of support / service provided'),
    t('[title] <small>website</small>'),
    t('ICT topics'),
    t('Geographical focus'),
    t('Page'),
  );
  $export['go_to_market_initiatives_2'] = $view;

  return $export;
}
