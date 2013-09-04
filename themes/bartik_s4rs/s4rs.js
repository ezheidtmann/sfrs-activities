(function($) {
  Drupal.behaviors.ezhCheckboxError = {
    attach: function (context, settings) {
      // apply special class indicating error to "chosen" widget when it replaces a select element
      // (we can't use class "error" because this highlights selectable terms in red)
      $('select.error.chzn-done', context).next('div.chzn-container').addClass('js-inherited-error');

      // apply "error" class to autocomplete_deluxe widget div
      $('div.autocomplete-deluxe-container:has(input.error)').addClass('js-inherited-error');
    }
  };
})(jQuery);
