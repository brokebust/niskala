<?php

/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function agilebase_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Implements hook_page_build().
 */
function agilebase_page_build(&$page) {
  // Allow for both navbar and admin_menu to be enabled.
  // Full admins get admin_menu, others get navbar.
  if (isset($page['page_top']['navbar'])) {
    // If the user can access the navbar, hide if they can see the admin menu.
    if (user_access('access navbar')) {
      $page['page_top']['navbar']['#access'] = !user_access('access administration menu');
    }
  }
}
