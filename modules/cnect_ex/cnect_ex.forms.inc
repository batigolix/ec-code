<?php

/**
 * @file
 * Contains forms for the CNECT editor experience module.
 */

/**
 * Defines form cnect_ex_update_xmlsitemap_form.
 */
function cnect_ex_update_xmlsitemap_form($form, $form_state) {
  $form['form_intro'] = array(
    '#markup' => t('You replace the data in the XML sitemap table with the data entered in the textarea below. <strong>By doing so you override user entered data</strong>'),
  );
  $form['xmlsitemap_data'] = array(
    '#type' => 'textarea',
    '#title' => t('XML sitemap data'),
    '#description' => t('Enter a list of XML sitemap values that must be updated'),
    '#default_value' => '',
    '#required' => TRUE,
  );
  $form['xmlsitemap_sample'] = array(
    '#markup' => '<div>Enter priority and url alias separated by comma. Priority 0 will disable the item in the xml sitemap. Sample input:<pre>0.1,/charles-ess-biography
0.2,/jean-gabriel-ganascia-biography
0.3,/judith-simon-biography
0.4,/luciano-floridi-biography
0,/may-thorseth-biography
0,/mireille-hildebrandt-biography
0.9,/about-the-webmaster
</pre></div>',
  );
  return confirm_form($form, t('Update the XML sitemap data?'), 'admin/config/search/xmlsitemap/update_xmlsitemap');
}

/**
 * Submits form cnect_ex_update_xmlsitemap_form.
 */
function cnect_ex_update_xmlsitemap_form_submit($form, &$form_state) {
  _cnect_ex_update_xmlsitemap($form_state);
  $form_state['redirect'] = 'admin/config/search/xmlsitemap/update_xmlsitemap';
}

/**
 * Updates xmlsitemap.
 *
 * @param array $form_state
 *   An array which stores information about the form.
 */
function _cnect_ex_update_xmlsitemap($form_state) {
  $items = _cnect_ex_process_csv($form_state['values']['xmlsitemap_data']);
  foreach ($items as $item) {
    $path = drupal_get_normal_path(ltrim($item['alias'], '/'));
    if (isset($path)) {
      $query = db_update('xmlsitemap')->fields(array(
        'priority' => $item['priority'],
        'priority_override' => 1,
        'status' => $item['status'],
        'status_override' => $item['status_override'],
      ))->condition('loc', $path, '=');
      $result = $query->execute();
      $msg = $result == 1 ? 'Sitemap item updated' : 'Sitemap item not updated';
      watchdog('cnect_ex', '@msg for path @path (alias @alias) to priority @priority', array(
        '@path' => $path,
        '@alias' => $item['alias'],
        '@priority' => $item['priority'],
        '@msg' => $msg,
      ), WATCHDOG_INFO);
    }
  }
}

/**
 * Creates XML sitemap items from CSV data.
 *
 * @param string $data
 *   String containing CSV data.
 *
 * @return array
 *   Associative array with items that can be used to update the XML sitemap.
 */
function _cnect_ex_process_csv($data) {
  $lines = explode("\n", $data);
  $csv_data = array();
  foreach ($lines as $line) {
    if (isset($line[0])) {
      $csv_data[] = str_getcsv($line);
    }
  }
  foreach ($csv_data as $item) {
    $items[] = array(
      'priority' => $item[0],
      'alias' => trim($item[1]),
      'status' => $item[0] == 0 ? 0 : 1,
      'status_override' => $item[0] == 0 ? 1 : 0,
    );
  }
  return $items;
}

/**
 * Defines form that allows administrators to bulk update aliases. DAE-1434.
 */
function cnect_ex_update_aliases_form($form, $form_state) {
  $form['form_intro'] = array(
    '#markup' => t('You update the data in the aliases table with the data entered in the textarea below. Where needed redirects are being created. <strong>Warning: you override user entered data</strong>'),
  );
  $form['aliases_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Aliases data'),
    '#description' => t('Enter a list of aliases that must be updated'),
    '#default_value' => '',
    '#required' => TRUE,
  );
  $form['aliases_sample'] = array(
    '#markup' => '<div><p>Enter action, source and alias separated by comma. Sample input:<pre>d, 16470, node/10622, future-and-emerging-technologies<br />d, 16484, node/10622, future-and-emerging-technologies-fet<br />m, 94916, node/10622, fet<br />d, 98331, node/10622, future-emerging-technologies-fet<br />m, 16477, node/10627, fet-proactive<br />k, 4778, node/1063, workshop-17-spectrum-wireless-innovation-europe<br />d, 16486, node/10630, fet-flagships<br /></pre></p><p>Actions are: d - delete; m - move to redirect; k - keep (NOP).</p></div>',
  );
  return confirm_form($form, t('Bulk update the aliases'), 'admin/config/search/path/update_aliases');
}

/**
 * Submits form cnect_ex_update_aliases_form.
 */
function cnect_ex_update_aliases_form_submit($form, &$form_state) {

  // Fetches items from the CSV input.
  $items = _cnect_ex_process_aliases_csv($form_state['values']['aliases_data']);

  // Prepares batch.
  batch_set(_cnect_ex_update_aliases($items));

  // Redirects to form.
  $form_state['redirect'] = 'admin/config/search/path/update_aliases';
}

/**
 * Creates alias update items from CSV data.
 *
 * @param string $data
 *   String containing CSV data.
 *
 * @return array
 *   Associative array with items that can be used to update the aliases.
 */
function _cnect_ex_process_aliases_csv($data) {
  $lines = explode("\n", $data);
  $csv_data = array();
  foreach ($lines as $line) {
    if (isset($line[0])) {
      $csv_data[] = str_getcsv($line);
    }
  }
  $items = array();
  foreach ($csv_data as $item) {
    if (isset($item[0]) && isset($item[1]) && isset($item[2])) {
      $items[] = array(
        'action' => trim($item[0]),
        'pid' => trim($item[1]),
        'source' => trim($item[2]),
        'alias' => trim($item[3]),
      );
    }
  }
  return $items;
}
