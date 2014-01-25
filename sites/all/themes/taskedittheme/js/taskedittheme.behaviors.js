(function ($) {

  /**
   * The recommended way for producing HTML markup through JavaScript is to write
   * theming functions. These are similiar to the theming functions that you might
   * know from 'phptemplate' (the default PHP templating engine used by most
   * Drupal themes including Omega). JavaScript theme functions accept arguments
   * and can be overriden by sub-themes.
   *
   * In most cases, there is no good reason to NOT wrap your markup producing
   * JavaScript in a theme function.
   */
  Drupal.theme.prototype.taskeditthemeExampleButton = function (path, title) {
    // Create an anchor element with jQuery.
    return $('<a href="' + path + '" title="' + title + '">' + title + '</a>');
  };

  /**
   * Behaviors are Drupal's way of applying JavaScript to a page. The advantage
   * of behaviors over simIn short, the advantage of Behaviors over a simple
   * document.ready() lies in how it interacts with content loaded through Ajax.
   * Opposed to the 'document.ready()' event which is only fired once when the
   * page is initially loaded, behaviors get re-executed whenever something is
   * added to the page through Ajax.
   *
   * You can attach as many behaviors as you wish. In fact, instead of overloading
   * a single behavior with multiple, completely unrelated tasks you should create
   * a separate behavior for every separate task.
   *
   * In most cases, there is no good reason to NOT wrap your JavaScript code in a
   * behavior.
   *
   * @param context
   *   The context for which the behavior is being executed. This is either the
   *   full page or a piece of HTML that was just added through Ajax.
   * @param settings
   *   An array of settings (added through drupal_add_js()). Instead of accessing
   *   Drupal.settings directly you should use this because of potential
   *   modifications made by the Ajax callback that also produced 'context'.
   */

  Drupal.behaviors.taskeditthemeInit = {
    attach: function (context, settings) {
      // By using the 'context' variable we make sure that our code only runs on
      // the relevant HTML. Furthermore, by using jQuery.once() we make sure that
      // we don't run the same piece of code for an HTML snippet that we already
      // processed previously. By using .once('tet-init') all processed elements will
      // get tagged with a 'tet-init-processed' class, causing all future invocations
      // of this behavior to ignore them.
      // 'tet' is a alias for task edit theme

$checkbox = $('.draggable .form-type-checkbox');
$($checkbox, context).once('tet-init', function () {
      // CHECKBOX
      $checkboxIcon = $('<i></i>');
      $checkboxIcon.addClass('ion ion-android-checkmark');
      $(this).append($checkboxIcon);

      if($(this).find('input').is(":checked")) {
        $(this).addClass('active');
      }

      $(this).bind('click', function() {
        $(this).toggleClass('active');
        $input = $(this).children('input');
        $input.attr('checked', !$input.attr('checked'));
        console.log($input);
      });
      });

      // overlay container
      var $overlaycontainer = window.parent.document.getElementById('overlay-container');

      $($overlaycontainer, context).once('tet-init', function () {
        // CLICK ON BG
        $('#overlay-close-bg').not('#overlay').click(function (event) {
          // prevent parent elements from triggering
          event.stopPropagation();
          // simulated click on close
          $('#overlay-close').click();
        });
        // ESC KEYPRESS
        $(document).keydown(function(event) {
          if(event.which == 27) {
          // prevent default event from triggering
          event.preventDefault;
          event.stopPropagation();
          $('#overlay-close').click();
          }
        });
      });
    }
  }

})(jQuery);
