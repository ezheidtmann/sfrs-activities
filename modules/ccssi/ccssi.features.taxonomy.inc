<?php
/**
 * @file
 * ccssi.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ccssi_taxonomy_default_vocabularies() {
  return array(
    'ccssi' => array(
      'name' => 'Common Core State Standards',
      'machine_name' => 'ccssi',
      'description' => 'CCSS identifiers, dot notation, in hierarchical vocabulary',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
