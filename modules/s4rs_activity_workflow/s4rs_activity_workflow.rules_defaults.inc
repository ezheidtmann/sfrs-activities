<?php
/**
 * @file
 * s4rs_activity_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function s4rs_activity_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_activity_comment_new_comment'] = entity_import('rules_config', '{ "rules_activity_comment_new_comment" : {
      "LABEL" : "Activity comment: new comment",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : [ "comment_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "s4rs_activity" : "s4rs_activity" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "comment:node:author:mail" ],
            "subject" : "New comment from \\u0022[comment:author]\\u0022 on your activity \\u0022[comment:node:title]\\u0022",
            "message" : "Hello [comment:node:author],\\r\\n\\r\\nYou just received a new comment on your activity titled \\u0022[comment:node:title]\\u0022:\\r\\n\\r\\nAuthor: [comment:author]\\r\\nDate: [comment:created]\\r\\n\\r\\n[comment:body]\\r\\n",
            "language" : [ "comment:node:language" ]
          }
        },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "New comment from \\u0022[comment:author]\\u0022 on the activity \\u0022[comment:node:title]\\u0022",
            "message" : "The teacher \\u0022[comment:node:author]\\u0022 just received a new comment on the activity titled \\u0022[comment:node:title]\\u0022:\\r\\n\\r\\nAuthor: [comment:author]\\r\\nDate: [comment:created]\\r\\n\\r\\n[comment:body]\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_activity_new_activity_saved'] = entity_import('rules_config', '{ "rules_activity_new_activity_saved" : {
      "LABEL" : "Activity: new activity saved",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "s4rs_activity" : "s4rs_activity" } }
          }
        },
        { "NOT node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "New activity: \\u0022[node:title]\\u0022 by \\u0022[node:author]\\u0022",
            "message" : "A new activity has been posted by the user \\u0022[node:author]\\u0022 titled \\u0022[node:title].\\u0022 It is currently unpublished; it must be approved before it can be published.\\r\\n\\r\\nCheck it out: [node:url]"
          }
        }
      ]
    }
  }');
  $items['rules_activity_new_revision_saved'] = entity_import('rules_config', '{ "rules_activity_new_revision_saved" : {
      "LABEL" : "Activity: unpublished revision saved",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "revisioning", "rules" ],
      "ON" : [ "revisioning_post_update" ],
      "IF" : [
        { "revisioning_condition_revision_is" : { "node" : [ "node" ], "revision_type" : { "value" : { "2" : "2" } } } },
        { "node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Your changes to this activity have been saved. Other visitors will continue to see the previous version of this activity until your changes have been approved by Solar 4R Schools staff." } },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "New revision for \\u0022[node:title]\\u0022 by \\u0022[node:author]\\u0022 ([site:name])",
            "message" : "The user \\u0022[node:author]\\u0022 has submitted a revision to the activity called \\u0022[node:title].\\u0022\\r\\n\\r\\nSee the original: [node:url]\\/revisions\\/[current-revision:vid]\\/view\\r\\nSee the new revision: [node:url]\\/revisions\\/[node:vid]\\/view\\r\\nSee differences: [node:url]\\/revisions\\/[node:vid]\\/compare"
          }
        }
      ]
    }
  }');
  $items['rules_comment_deleted_email_author'] = entity_import('rules_config', '{ "rules_comment_deleted_email_author" : {
      "LABEL" : "Comment deleted: email author",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "comment" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : [ "comment_delete" ],
      "IF" : [
        { "NOT data_is" : { "data" : [ "comment:author" ], "value" : [ "site:current-user" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[comment:author:mail]",
            "subject" : "You comment on the activity \\u0022[comment:node:title]\\u0022 has been deleted",
            "message" : "Hello [comment:author],\\r\\n\\r\\nWe\\u0027re sorry to report that your comment posted [comment:created] has been deleted by the user [site:current-user]. You had written:\\r\\n\\r\\n[comment:body]\\r\\n\\r\\nTo see the activity, visit this link: [comment:node:url]\\r\\n",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_comment_deleted_email_moderators'] = entity_import('rules_config', '{ "rules_comment_deleted_email_moderators" : {
      "LABEL" : "Comment deleted: email moderators",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "comment" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : [ "comment_delete" ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "A comment on the activity \\u0022[comment:node:title]\\u0022 has been deleted",
            "message" : "The comment posted [comment:created] by [comment:author] has been deleted by the user [site:current-user]. It used to read:\\r\\n\\r\\n[comment:body]\\r\\n\\r\\nTo see the activity, visit this link: [comment:node:url]\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_comment_deleted_email_node_author'] = entity_import('rules_config', '{ "rules_comment_deleted_email_node_author" : {
      "LABEL" : "Comment deleted: email node author",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "comment" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : [ "comment_delete" ],
      "IF" : [
        { "NOT data_is" : { "data" : [ "site:current-user" ], "value" : [ "comment:node:author" ] } },
        { "NOT data_is" : { "data" : [ "comment:author" ], "value" : [ "comment:node:author" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[comment:node:author:mail]",
            "subject" : "A comment on your activity \\u0022[comment:node:title]\\u0022 has been deleted",
            "message" : "Hello [comment:node:author],\\r\\n\\r\\nA comment posted [comment:created] by [comment:author] has been deleted by the user [site:current-user]. The comment used to read:\\r\\n\\r\\n[comment:body]\\r\\n\\r\\nTo see the activity, visit this link: [comment:node:url]\\r\\n",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_comment_sticky_email_comment_author'] = entity_import('rules_config', '{ "rules_comment_sticky_email_comment_author" : {
      "LABEL" : "Comment sticky: email comment author",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "sticky" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_flagged_comment_sticky" ],
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "flagging-user" ],
            "value" : [ "flagged-comment:node:author" ]
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "flagged-comment:author:mail" ],
            "subject" : "Your comment on the activity titled \\u0022[flagged-comment:node:title]\\u0022 has been made sticky!\\r\\n",
            "message" : "The user \\u0022[flagging-user:name]\\u0022 has made \\u0022sticky\\u0022 your comment on the activity titled \\u0022[flagged-comment:node:title]\\u0022.\\r\\n\\r\\nSee it: [flagged-comment:url]\\r\\nAuthor: [flagged-comment:author]\\r\\nDate: [flagged-comment:created]\\r\\n\\r\\n[flagged-comment:body]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_comment_sticky_email_node_author'] = entity_import('rules_config', '{ "rules_comment_sticky_email_node_author" : {
      "LABEL" : "Comment sticky: email node author",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_flagged_comment_sticky" ],
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "flagging-user" ],
            "value" : [ "flagged-comment:node:author" ]
          }
        },
        { "NOT data_is" : {
            "data" : [ "flagged-comment:author" ],
            "value" : [ "flagged-comment:node:author" ]
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "flagged-comment:node:author:mail" ],
            "subject" : "A comment on \\u0022[flagged-comment:node:title]\\u0022 is now sticky",
            "message" : "The user \\u0022[flagging-user:name]\\u0022 has made \\u0022sticky\\u0022 the following comment on your activity titled \\u0022[flagged-comment:node:title]\\u0022.\\r\\n\\r\\nSee it: [flagged-comment:url]\\r\\nAuthor: [flagged-comment:author]\\r\\nDate: [flagged-comment:created]\\r\\n\\r\\n[flagged-comment:body]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_comment_sticky_un_sticky_by_admin'] = entity_import('rules_config', '{ "rules_comment_sticky_un_sticky_by_admin" : {
      "LABEL" : "Comment sticky: email moderators",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "sticky" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_flagged_comment_sticky" ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "Comment on \\u0022[flagged-comment:node:title]\\u0022 is now sticky",
            "message" : "The user \\u0022[flagging-user:name]\\u0022 has made \\u0022sticky\\u0022 the following comment on the activity titled \\u0022[flagged-comment:node:title]\\u0022.\\r\\n\\r\\nSee it: [flagged-comment:url]\\r\\nAuthor: [flagged-comment:author]\\r\\nDate: [flagged-comment:created]\\r\\n\\r\\n[flagged-comment:body]"
          }
        }
      ]
    }
  }');
  $items['rules_comment_un_sticky_by_admin_'] = entity_import('rules_config', '{ "rules_comment_un_sticky_by_admin_" : {
      "LABEL" : "Comment un-sticky: email moderators",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "sticky" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_unflagged_comment_sticky" ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "Comment on \\u0022[flagged-comment:node:title]\\u0022 is no longer sticky",
            "message" : "The user \\u0022[flagging-user:name]\\u0022 has made the following comment no longer sticky on the activity titled \\u0022[flagged-comment:node:title].\\u0022\\r\\n\\r\\nSee it [flagged-comment:url]\\r\\nAuthor: [flagged-comment:author]\\r\\nDate: [flagged-comment:created]\\r\\n\\r\\n[flagged-comment:body]"
          }
        }
      ]
    }
  }');
  $items['rules_comment_un_sticky_email_comment_author'] = entity_import('rules_config', '{ "rules_comment_un_sticky_email_comment_author" : {
      "LABEL" : "Comment un-sticky: email comment author",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "sticky" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_unflagged_comment_sticky" ],
      "IF" : [
        { "NOT data_is" : { "data" : [ "flagging-user" ], "value" : [ "flagged-comment:author" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "flagged-comment:author:mail" ],
            "subject" : "Your comment on the activity titled \\u0022[flagged-comment:node:title]\\u0022 is no longer sticky\\r\\n",
            "message" : "The user \\u0022[flagging-user:name]\\u0022 has made your comment no longer sticky on the activity titled \\u0022[flagged-comment:node:title]\\u0022.\\r\\n\\r\\nSee it: [flagged-comment:url]\\r\\nAuthor: [flagged-comment:author]\\r\\nDate: [flagged-comment:created]\\r\\n\\r\\n[flagged-comment:body]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_comment_un_sticky_email_node_author'] = entity_import('rules_config', '{ "rules_comment_un_sticky_email_node_author" : {
      "LABEL" : "Comment un-sticky: email node author",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "sticky" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_unflagged_comment_sticky" ],
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "flagging-user" ],
            "value" : [ "flagged-comment:node:author" ]
          }
        },
        { "NOT data_is" : {
            "data" : [ "flagged-comment:author" ],
            "value" : [ "flagged-comment:node:author" ]
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "flagged-comment:node:author:mail" ],
            "subject" : "A comment on \\u0022[flagged-comment:node:title]\\u0022 is no longer sticky",
            "message" : "The user \\u0022[flagging-user:name]\\u0022 has made the following comment no longer sticky on your activity titled \\u0022[flagged-comment:node:title]\\u0022.\\r\\n\\r\\nSee it: [flagged-comment:url]\\r\\nAuthor: [flagged-comment:author]\\r\\nDate: [flagged-comment:created]\\r\\n\\r\\n[flagged-comment:body]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
