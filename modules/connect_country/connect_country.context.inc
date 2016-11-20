<?php
/**
 * @file
 * connect_country.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function connect_country_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'country';
  $context->description = '';
  $context->tag = ' dae featurized';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'country/*' => 'country/*',
        '~country/*/cordis' => '~country/*/cordis',
        '~country/*/whatwedo' => '~country/*/whatwedo',
      ),
    ),
    'taxonomy_term' => array(
      'values' => array(
        'country' => 'country',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-97',
        ),
        'connect_country-scoreboard' => array(
          'module' => 'connect_country',
          'delta' => 'scoreboard',
          'region' => 'content',
          'weight' => '-10',
        ),
        'connect_country-going' => array(
          'module' => 'connect_country',
          'delta' => 'going',
          'region' => 'content',
          'weight' => '-8',
        ),
        'connect_country-broadband' => array(
          'module' => 'connect_country',
          'delta' => 'broadband',
          'region' => 'content',
          'weight' => '-6',
        ),
        'connect_country-business' => array(
          'module' => 'connect_country',
          'delta' => 'business',
          'region' => 'content',
          'weight' => '-4',
        ),
        'connect_country-champion' => array(
          'module' => 'connect_country',
          'delta' => 'champion',
          'region' => 'content',
          'weight' => '-2',
        ),
        'connect_country-generic_country_info' => array(
          'module' => 'connect_country',
          'delta' => 'generic_info',
          'region' => 'content',
          'weight' => '1',
        ),
        'nexteuropa_newsroom-newsroom_summary_blocks' => array(
          'module' => 'nexteuropa_newsroom',
          'delta' => 'newsroom_summary_blocks',
          'region' => 'content_tab1',
          'weight' => '-10',
        ),
        'connect_country-cordis' => array(
          'module' => 'connect_country',
          'delta' => 'cordis',
          'region' => 'content_tab3',
          'weight' => '-10',
        ),
        'boxes-main_cta_interact' => array(
          'module' => 'boxes',
          'delta' => 'main_cta_interact',
          'region' => 'sidebar_right',
          'weight' => '-11',
        ),
        'digital_agenda_general-dae_twitter' => array(
          'module' => 'digital_agenda_general',
          'delta' => 'dae_twitter',
          'region' => 'sidebar_right',
          'weight' => '-5',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_right',
          'weight' => '9',
        ),
      ),
    ),
    'digital_agenda_general_tabs' => array(
      'content' => array(
        'id' => 'Dashboard',
        'title' => 'Dashboard',
      ),
      'content_tab1' => array(
        'id' => 'Whatwedo',
        'title' => 'What we do',
      ),
      'content_tab2' => array(
        'id' => 'Newsroom',
        'title' => 'Newsroom',
      ),
      'content_tab3' => array(
        'id' => 'Cordis',
        'title' => 'EU investments',
      ),
      'content_tab4' => array(
        'id' => 'Library',
        'title' => 'Library',
      ),
    ),
    'theme_html' => array(
      'class' => 'country-page',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Country pages');
  $export['country'] = $context;

  return $export;
}
