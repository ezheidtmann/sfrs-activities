<?php
/**
 * @file
 * s4rs_activity_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function s4rs_activity_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function s4rs_activity_search_default_search_api_index() {
  $items = array();
  $items['activity_index'] = entity_import('search_api_index', '{
    "name" : "Activity index",
    "machine_name" : "activity_index",
    "description" : null,
    "server" : "basic_database_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "nid" : { "type" : "integer" },
        "vid" : { "type" : "integer" },
        "is_new" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "status" : { "type" : "boolean" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "comment_count" : { "type" : "integer" },
        "comment_count_new" : { "type" : "integer" },
        "field_learning_goals" : { "type" : "list\\u003Ctext\\u003E" },
        "field_time_required" : { "type" : "integer" },
        "field_materials" : { "type" : "list\\u003Ctext\\u003E" },
        "field_subject_areas" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_student_key_vocab" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_grade_level" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_science_kit_components" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ccssi_terms" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "attachments_field_activity_pdf" : { "type" : "text" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "body:value" : { "type" : "text" },
        "field_activity_pdf:file" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "field_activity_pdf:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_subject_areas:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_student_key_vocab:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_activity_pdf:file:name" : { "type" : "list\\u003Ctext\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "s4rs_activity" : "s4rs_activity" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb" }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_learning_goals" : true,
              "field_materials" : true,
              "field_ccss_text" : true,
              "body:value" : true,
              "field_activity_pdf:description" : true,
              "field_subject_areas:name" : true,
              "field_student_key_vocab:name" : true,
              "field_activity_pdf:file:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_learning_goals" : true,
              "field_materials" : true,
              "field_ccss_text" : true,
              "body:value" : true,
              "field_activity_pdf:description" : true,
              "field_subject_areas:name" : true,
              "field_student_key_vocab:name" : true,
              "field_activity_pdf:file:name" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_learning_goals" : true,
              "field_materials" : true,
              "field_ccss_text" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "field_activity_pdf:description" : true,
              "field_subject_areas:name" : true,
              "field_student_key_vocab:name" : true,
              "field_activity_pdf:file:name" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_learning_goals" : true,
              "field_materials" : true,
              "field_ccss_text" : true,
              "body:value" : true,
              "field_activity_pdf:description" : true,
              "field_subject_areas:name" : true,
              "field_student_key_vocab:name" : true,
              "field_activity_pdf:file:name" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function s4rs_activity_search_default_search_api_server() {
  $items = array();
  $items['basic_database_server'] = entity_import('search_api_server', '{
    "name" : "Basic Database Server",
    "machine_name" : "basic_database_server",
    "description" : "using search_api_db module",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "2",
      "indexes" : {
        "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_title",
            "type" : "text",
            "boost" : "5.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index_promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index_sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index_created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index_changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index_author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "comment_count" : {
            "table" : "search_api_db_default_node_index_comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_body_value",
            "type" : "text",
            "boost" : "1.0"
          }
        },
        "activity_index" : {
          "nid" : {
            "table" : "search_api_db_activity_index_nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "vid" : {
            "table" : "search_api_db_activity_index_vid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "is_new" : {
            "table" : "search_api_db_activity_index_is_new",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_activity_index_title",
            "type" : "text",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_activity_index_status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_learning_goals" : {
            "table" : "search_api_db_activity_index_field_learning_goals",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_time_required" : {
            "table" : "search_api_db_activity_index_field_time_required",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_materials" : {
            "table" : "search_api_db_activity_index_field_materials",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_subject_areas" : {
            "table" : "search_api_db_activity_index_field_subject_areas",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_student_key_vocab" : {
            "table" : "search_api_db_activity_index_field_student_key_vocab",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_grade_level" : {
            "table" : "search_api_db_activity_index_field_grade_level",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_activity_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_activity_index_body_value",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_activity_pdf:file" : {
            "table" : "search_api_db_activity_index_field_activity_pdf_file",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_activity_pdf:description" : {
            "table" : "search_api_db_activity_index_field_activity_pdf_description",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_subject_areas:name" : {
            "table" : "search_api_db_activity_index_field_subject_areas_name",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_student_key_vocab:name" : {
            "table" : "search_api_db_activity_index_field_student_key_vocab_name",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_activity_pdf:file:name" : {
            "table" : "search_api_db_activity_index_field_activity_pdf_file_name",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_activity_index_author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_viewed" : {
            "table" : "search_api_db_activity_index_search_api_viewed",
            "type" : "text",
            "boost" : "1.0"
          },
          "attachments_field_activity_pdf" : {
            "table" : "search_api_db_activity_index_attachments_field_activity_pdf",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_activity_index_search_api_access_node",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_science_kit_components" : {
            "table" : "search_api_db_activity_index_field_science_kit_components",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_activity_index_changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "comment_count" : {
            "table" : "search_api_db_activity_index_comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "comment_count_new" : {
            "table" : "search_api_db_activity_index_comment_count_new",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_ccssi_terms" : {
            "table" : "search_api_db_activity_index_field_ccssi_terms",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
