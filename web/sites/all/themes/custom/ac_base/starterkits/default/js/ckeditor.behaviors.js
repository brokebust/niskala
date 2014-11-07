(function ($) {
  Drupal.behaviors.ckeditor_modifications = {
    attach: function (context, settings) {
      $('.text-format-wrapper a.ckeditor_links', context).once('modified', function () {
        console.log($(this).siblings('fieldset'));
        var fieldset = $(this).siblings('fieldset').children('.fieldset-wrapper');
        $(this).prependTo(fieldset).wrap('<div class="ckeditor_links_wrapper"></div>');
      });
    }
  };

})(jQuery);