# cnect_ex module readme

## Description

This module provides:
- views and contributed modules that help editor managing content.
- context to set the menu parent item (to place any page or section in the main menu hierarchy).
- UI to do bulk updates to the XML sitemap

## User stories
- As an editor I can see an overview (view) of older content on the website
- As an editor I can quickly select a menu item that is many levels down
- As an administrator I can create a context that associates with an item in the menu
- As an editor I can create a redirect so that request for a not longer existing page are being sent to a different page
- As an editor I can set metatags for facebook, opengraph, twitter and google
- As an editor I can see workbench & webform admin pages in the admin theme
-

## Configuration

Enable the module.

- This module sets the variable menu_override_parent_selector to TRUE
- This module sets the variable redirect_page_cache to TRUE
- This module disables obsolete menu management modules
- This module disables obsolete custom cnect_redir module

## Dependencies

This module requires:

- Menuperformance: https://www.drupal.org/project/menuperformance
- Redirect: https://www.drupal.org/project/redirect
- Metatag: https://www.drupal.org/project/metatag
