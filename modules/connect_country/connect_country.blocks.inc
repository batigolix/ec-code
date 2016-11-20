<?php

/**
 * @file
 * Contains block definitions.
 */

/**
 * Implements hook_block_info().
 *
 * Defines custom blocks for the Connect Country.
 */
function connect_country_block_info() {
  $blocks['champion'] = array(
    'info' => t('Connect Country: Champion'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  );
  $blocks['scoreboard'] = array(
    'info' => t('Connect Country: Scoreboard'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  );
  $blocks['going'] = array(
    'info' => t('Connect Country: Going local'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  );
  $blocks['cordis'] = array(
    'info' => t('Connect Country: Cordis'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  );
  $blocks['broadband'] = array(
    'info' => t('Connect Country: Broadband'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  );
  $blocks['business'] = array(
    'info' => t('Connect Country: Business'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  );
  $blocks['generic_info'] = array(
    'info' => t('Connect Country: Generic country information'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 *
 * Defines title and content of custom blocks.
 */
function connect_country_block_view($delta = '') {
  $tid = _connect_country_tid();
  $blocks = array();
  switch ($delta) {
    case 'champion':
      $blocks['subject'] = t('Digital Champion');
      $blocks['content'] = _connect_country_champion($tid);
      break;

    case 'scoreboard':
      $blocks['subject'] = t('Digital Agenda Scoreboard');
      $blocks['content'] = _connect_country_scoreboard($tid);
      break;

    case 'going':
      $blocks['subject'] = t('Going local');
      $blocks['content'] = _connect_country_going($tid);
      break;

    case 'cordis':
      $blocks['subject'] = t('EU funded projects');
      if (module_exists('cordis_feature')) {
        $blocks['content'] = _connect_country_cordis($tid);
      }
      break;

    case 'broadband':
      $blocks['subject'] = t('Broadband');
      $blocks['content'] = _connect_country_broadband($tid);
      break;

    case 'business':
      $blocks['subject'] = t('Business');
      $blocks['content'] = _connect_country_business($tid);
      break;

    case 'generic_info':
      $blocks['subject'] = t('More information');
      $blocks['content'] = _connect_country_generic_info();
      break;
  }
  return $blocks;
}

/**
 * Provides content for the Digital champion block.
 *
 * @param int $tid
 *   Term ID.
 *
 * @return array
 *   Renderable list of nodes.
 */
function _connect_country_champion($tid) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'digital_champion')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('created', 'DESC')
    ->fieldCondition('field_country', 'tid', $tid)
    ->fieldCondition('field_biography_type', 'value', 'digital_champion', '=')
    ->propertyOrderBy('sticky', 'DESC')
    ->range(0, 1);
  $result = $query->execute();
  if (!empty($result['node'])) {
    $block = node_view_multiple(node_load_multiple(array_keys($result['node'])), 'teaser');
    return $block;
  }
}

/**
 * Provides content for the Scoreboard block.
 *
 * @param int $tid
 *   Term ID.
 *
 * @return array
 *   Renderable list of nodes.
 */
function _connect_country_scoreboard($tid) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'score_board')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('created', 'DESC')
    ->fieldCondition('field_shared_country', 'tid', $tid)
    ->propertyOrderBy('sticky', 'DESC')
    ->range(0, 1);
  $result = $query->execute();
  if (!empty($result['node'])) {
    $block = node_view_multiple(node_load_multiple(array_keys($result['node'])), 'teaser');
    return $block;
  }
}

/**
 * Provides content for the Going local block.
 *
 * @param int $tid
 *   Term ID.
 *
 * @return array
 *   Renderable list of nodes.
 */
function _connect_country_going($tid) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('created', 'DESC')
    ->entityCondition('bundle', 'going_local')
    ->fieldCondition('field_shared_country', 'tid', $tid)
    ->propertyOrderBy('sticky', 'DESC')
    ->range(0, 1);
  $result = $query->execute();
  if (!empty($result['node'])) {
    $block = node_view_multiple(node_load_multiple(array_keys($result['node'])), 'teaser');
    return $block;
  }
}

/**
 * Provides content for the Cordis block.
 *
 * @param int $tid
 *   Term ID.
 *
 * @return array
 *   Renderable list of nodes.
 */
function _connect_country_cordis($tid) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('created', 'DESC')
    ->entityCondition('bundle', 'project')
    ->fieldCondition('field_shared_country', 'tid', $tid)
    ->propertyOrderBy('sticky', 'DESC')
    ->range(0, 5);
  $result = $query->execute();
  if (!empty($result['node'])) {
    $block = node_view_multiple(node_load_multiple(array_keys($result['node'])), 'teaser');
    $block['more']['#markup'] = l(t('More'), "country/{$tid}/cordis");
    return $block;
  }
}

/**
 * Provides content for the broadband block.
 *
 * @param int $tid
 *   Term ID.
 *
 * @return array
 *   Renderable list of nodes.
 */
function _connect_country_broadband($tid) {
  $tag_tids = variable_get('connect_country_broadband_tag_tids');
  if ($tag_tids) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('status', 1)
      ->propertyOrderBy('created', 'DESC')
      ->entityCondition('bundle', 'page')
      ->fieldCondition('field_shared_country', 'tid', $tid)
      ->fieldCondition('field_tags', 'tid', $tag_tids, 'IN')
      ->propertyOrderBy('sticky', 'DESC')
      ->range(0, 3);
    $result = $query->execute();
    if (!empty($result['node'])) {
      $block = node_view_multiple(node_load_multiple(array_keys($result['node'])), 'mini_teaser');
      return $block;
    }
  }
}

/**
 * Provides content for the business block.
 *
 * @param int $tid
 *   Term ID.
 *
 * @return array
 *   Renderable list of nodes.
 */
function _connect_country_business($tid) {
  $tag_tids = variable_get('connect_country_business_tag_tids');
  if ($tag_tids) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('status', 1)
      ->propertyOrderBy('created', 'DESC')
      ->entityCondition('bundle', 'page')
      ->fieldCondition('field_shared_country', 'tid', $tid)
      ->fieldCondition('field_tags', 'tid', $tag_tids, 'IN')
      ->propertyOrderBy('sticky', 'DESC')
      ->range(0, 3);
    $result = $query->execute();
    if (!empty($result['node'])) {
      $block = node_view_multiple(node_load_multiple(array_keys($result['node'])), 'mini_teaser');
      return $block;
    }
  }
}

/**
 * Provides content for the generic info block.
 *
 * @return array
 *   Renderable block content.
 */
function _connect_country_generic_info() {

  // Checks for custom block content.
  $content = variable_get('generic_info_content', '');
  if (!empty($content)) {
    $block['#markup'] = $content;
  }

  // Uses the default if there is no custom content.
  else {
    $items = array(
      array(
        'data' => l(t('National regulatory authorities for Telecoms rules'), 'national-regulatory-authorities'),
      ),
      array(
        'data' => l(t('Open data portals on public information'), 'open-data-portals'),
      ),
      array(
        'data' => l(t('Studies on e-health in EU member states'), 'ehealth-studies-overview'),
      ),
      array(
        'data' => l(t('Study on  ICT in schools in EU member states'), 'survey-schools-ict-education'),
      ),
    );
    $block = array(
      '#theme' => 'item_list',
      '#items' => $items,
      '#title' => NULL,
    );
  }
  return $block;
}

/**
 * Fetches the country term ID.
 *
 * @return int
 *   Term ID.
 */
function _connect_country_tid() {
  $taxonomy_term = menu_get_object('taxonomy_term', 2);
  return $taxonomy_term->tid;
}

/**
 * Implements hook_block_configure().
 */
function connect_country_block_configure($delta = '') {
  $form = array();
  switch ($delta) {
    case 'generic_info':
      $form['generic_info_content'] = array(
        '#type' => 'textarea',
        '#title' => t('Block content'),
        '#rows' => 5,
        '#cols' => 20,
        '#description' => t('This will override the default generic info block content.'),
        '#default_value' => variable_get('generic_info_content', ''),
      );
      break;
  }
  return $form;
}

/**
 * Implements hook_block_save().
 */
function connect_country_block_save($delta = '', $edit = array()) {
  if ($delta == 'generic_info') {
    variable_set('generic_info_content', $edit['generic_info_content']);
  }
}
