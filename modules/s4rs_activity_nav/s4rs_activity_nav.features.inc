<?php
/**
 * @file
 * s4rs_activity_nav.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function s4rs_activity_nav_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
