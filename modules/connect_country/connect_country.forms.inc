<?php

/**
 * @file
 * Contains forms for Connect Country.
 */

/**
 * Constructs settings form.
 */
function connect_country_settings($form, &$form_state) {
  $form = array();

  // Fetches the tags to populate the options list.
  $v = taxonomy_vocabulary_machine_name_load('tags');
  if ($v) {
    $terms = taxonomy_get_tree($v->vid);
    foreach ($terms as $term) {
      $options[$term->tid] = $term->name;
    }
  }

  if ($options) {

    // Defines the Broadband tag field.
    $form['connect_country_broadband_tag_tids'] = array(
      '#type' => 'select',
      '#title' => t('Broadband tag'),
      '#options' => $options,
      '#description' => t('Content categorised with this tag will be shown in the Broadband block in the country page'),
      '#default_value' => variable_get('connect_country_broadband_tag_tids', array()),
      '#chosen' => TRUE,
      '#multiple' => TRUE,
    );

    // Defines the Business tag field.
    $form['connect_country_business_tag_tids'] = array(
      '#type' => 'select',
      '#title' => t('Business tag'),
      '#options' => $options,
      '#description' => t('Content categorised with this tag will be shown in the Business block in the country page'),
      '#default_value' => variable_get('connect_country_business_tag_tids', array()),
      '#chosen' => TRUE,
      '#multiple' => TRUE,
    );

    // Defines parent menu item.
    $form['connect_country_menu_parent'] = array(
      '#type' => 'textfield',
      '#title' => t('Parent menu item'),
      '#description' => t('System path of the menu item that should be shown as the parent in the menu tree.'),
      '#default_value' => variable_get('connect_country_menu_parent', 'node/78006'),
    );
  }

  return system_settings_form($form);
}
