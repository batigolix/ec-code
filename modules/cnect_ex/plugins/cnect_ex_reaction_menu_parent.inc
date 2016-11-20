<?php

/**
 * @file
 * Context.
 */

/**
 * Provides a context reaction that associates a menu parent.
 */
class CnectExMenuParentReaction extends context_reaction {

  /**
   * Provides options_form.
   *
   * @param array $context
   *   Context array.
   *
   * @return array
   *   Form array.
   */
  // @codingStandardsIgnoreStart
  public function options_form($context) {
  // @codingStandardsIgnoreEnd
    $value = $this->fetch_from_context($context);
    $form = array();
    $form['menu_parent'] = array(
      '#type' => 'textfield',
      '#title' => 'Path',
      '#description' => t("Path to the menu parent. For example, 'node/123456'"),
      '#default_value' => isset($value) ? $value : NULL,
    );
    return $form;
  }

  /**
   * We need a definition for this function but is not required.
   */
  public function execute(&$vars = NULL) {
    foreach ($this->get_contexts() as $context) {
      $paths = $this->fetch_from_context($context);
    }
    menu_tree_set_path('main-menu', $paths['menu_parent']);
  }

}
