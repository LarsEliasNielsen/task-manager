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

  Drupal.theme.prototype.tableDragChangedWarning = function () {
    $tabledragWarning = $('<div></div>');
    // $tabledragWarning.attr('id', 'draggable-changed');
    $tabledragWarning.addClass('tabledrag-changed-warning messages warning');

    $tabledragWarning.append(Drupal.theme('tableDragChangedMarker'));
    $tabledragWarning.append('<div class="tabledrag-changed text">' + Drupal.t('Save changes?') + '</div>');
    $tabledragWarning.append($('#edit-actions'));
    $('#edit-actions').toggleClass('ninja');

    $backlogTitle = $('#block-views-columns-backlog h2');
    // $warningWidth = $backlogTitle.outerWidth()
    // $warningHeight = $backlogTitle.outerHeight();

    // $tabledragWarning.css({ 'height':$warningHeight, 'width':$warningWidth });
    $('#block-views-columns-backlog .view-header').hide();

    $backlogTitle.replaceWith($tabledragWarning);

    return $tabledragWarning;
  };

  Drupal.theme.prototype.tableDragChangedMarker = function () {
    return '<div class="ion-alert-circled warning tabledrag-changed"></div>';
  };
  // TODO: remove tableDragChangedMarker after save

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

  Drupal.behaviors.taskmanagerthemeInit = {
    attach: function (context, settings) {
      // By using the 'context' variable we make sure that our code only runs on
      // the relevant HTML. Furthermore, by using jQuery.once() we make sure that
      // we don't run the same piece of code for an HTML snippet that we already
      // processed previously. By using .once('tmt-init') all processed elements will
      // get tagged with a 'tmt-init-processed' class, causing all future invocations
      // of this behavior to ignore them.

      // hidding Save button for tabledrag list
      $('#edit-actions').toggleClass('ninja');

      // placing tabledrag handle
      $('.tabledrag-handle', context).once('tmt-init', function () {
        // handle
        var $handle = $('.tabledrag-handle .handle');
        $handle.replaceWith('<i class="ion ion-ios7-more"></i>');
      });

      // placing 'Add a new task' icon
      $('#block-views-columns-backlog', context).once('tmt-init', function () {
        // header
        var $header = $('.view-header a');
        $header.prepend('<i class="ion ion-plus"></i>');
      });

      // SIDEBAR SCROLL
      $('#sidebar', context).once('tmt-init', function () {
        // accounting for admin-menu when setting variables
        if ($('body').hasClass('adminimal-menu')) {
          $viewportHeight = $(window).height()-29;
          $topHeight = $('#header').height() +29;
          $fixedTopHeight = '29px';
        } else {
          $viewportHeight = $(window).height();
          $topHeight = $('#header').height();
          $fixedTopHeight = '0';
        }

        $headerHeight = $('#header').height();
        $sidebarHeight = $viewportHeight - $headerHeight;
        $mainHeight = $('#main').height();

        // initial styling
        $('#sidebar').css({ 'top':$topHeight, 'height':$sidebarHeight });
        $('#sidebar-toggle').css({ 'top':$topHeight, 'height':$sidebarHeight });

        // use scroll function when #main is long enough
        if ($mainHeight >= $sidebarHeight) {
          $(window).scroll(function () {
            $windowScroll = $(window).scrollTop();
            if ($windowScroll < 0) {
              $windowScroll = 0;
            }
            if ($windowScroll >= 0 && $windowScroll < 118) {
              $('#sidebar').css({ 'top':$topHeight-$windowScroll, 'height':($sidebarHeight+$windowScroll) });
              $('#sidebar-toggle').css({ 'top':$topHeight-$windowScroll, 'height':($sidebarHeight+$windowScroll) });
            } else {
              $('#sidebar').css({ 'top':$fixedTopHeight, 'height':($viewportHeight) });
              $('#sidebar-toggle').css({ 'top':$fixedTopHeight, 'height':($viewportHeight) });
            }
          });
        }
      });
    }
  }

  Drupal.behaviors.userCookie = {
    attach: function(context, settings) {
      // if user is logged in
      if (Drupal.settings.user_js_uid > 0) {
        // GET COOKIE VALUE FUNCTION
        function getCookieValue(name) {
          var reg = new RegExp(name + "=([^;]+)");
          var value = reg.exec(document.cookie);
          return (value != null) ? unescape(value[1]) : null;
        }

        // INITIAL RUN
        // if cookie is set
        if ($.cookie('sidebar_pin_'+Drupal.settings.user_js_uid)) {
          // reading user cookie
          $cookieValue = getCookieValue('sidebar_pin_'+Drupal.settings.user_js_uid);
          console.log('cookie is set: '+$cookieValue);
        } else {
          // setting user cookie
          $.cookie('sidebar_pin_'+Drupal.settings.user_js_uid, '1', { path: '/', expires: 365 });
          $cookieValue = "1";
          console.log('cookie is not set');
        }

        // CREATING INPUT AND LABEL
        $form = $('<form></form>');
        $checkbox = $('<input>');
        $checkbox.attr('type', 'checkbox');
        $checkboxID = 'sidebar-checkbox';
        $checkbox.attr('id', $checkboxID);
        $checkbox.addClass('sidebar-checkbox');

        $label = $('<label></label>');
        $label.attr('for', $checkboxID);
        $label.addClass('sidebar-label');
        $label.attr('title', 'Pin sidebar');

        // SETTING AND READING VALUE
        $checkbox.attr('value', $cookieValue);
        if($checkbox.val() == true) {
          $checkbox.prop('checked', true);
          $label.attr('checked', true);
          $('#sidebar').removeClass('sidebar-collapsed');
          console.log('checked true');
        } else {
          $checkbox.prop('checked', false);
          $label.attr('checked', false);
          $('#sidebar').addClass('sidebar-collapsed');
          console.log('checked false');
        }

        // APPENDING TO BLOCK WRAPPER
        $sidebarContainer = $('#sidebar .block--views-revision-history-history');
        $form.append($checkbox);
        $label.append('<i class="ion ion-pin"></i>');
        $form.append($label);
        $sidebarContainer.append($form);

        // ON CHANGE
        $($checkbox).change(function(){
          if ($(this).is(':checked')) {
            $newValue = "1";
          } else {
            $newValue = "0";
          }
          $.cookie('sidebar_pin_'+Drupal.settings.user_js_uid, $newValue, { path: '/', expires: 365 });
          console.log('new cookie: '+$newValue);
        });
      }
    }
  };

  Drupal.behaviors.taskmanagerthemeHover = {
    attach: function (context, settings) {

      $('#draggableviews-table-columns-backlog', context).once('tmt-hover', function () {
        // task
        var $task = $('#draggableviews-table-columns-backlog tr.draggable');
        // initially hidden
        $task.find('.ion-ios7-more').hide();
        // hover
        $task.hover(
          function () {
            $(this).find('.ion-ios7-more').show();
          }, 
          function () {
            $(this).find('.ion-ios7-more').hide();
          }
        );
      });
    }
  }

  Drupal.behaviors.taskmanagerthemeSidebar = {
    attach: function (context, settings) {
      $('#sidebar', context).once('tmt-sidebar', function () {
        // SETTING ELEMENT VARIABLES
          var $sidebar = $('#sidebar');
          var $sidebartoggle = $('#sidebar-toggle');
          var $main = $('#main');
          var $rotate = $('#ion-chevron-up');

        // INITIAL
        if ($sidebar.hasClass('sidebar-collapsed')) {
          $sidebar.css({ 'right':'-230px' });
          $sidebartoggle.css({ 'right':'0' });
          $main.css({ 'padding-right':'0' });
          $rotate.toggleClass('icon-rotate');
        }

        // CLICK
        $('#sidebar-toggle').click(function() {
          // sidebar
          $sidebar.animate({
            right: parseInt($sidebar.css('right'),10) == 0 ?
              -$sidebar.outerWidth(true) :
              0
          }, 100);
          $sidebar.toggleClass('sidebar-collapsed');

          // sidebartoggle
          $sidebartoggle.animate({
            right: parseInt($sidebartoggle.css('right'),10) == 0 ?
              $sidebar.outerWidth(true) :
              0
          }, 100);

          // main
          $main.animate({
            paddingRight: parseInt($main.css('padding-right'),10) == 0 ?
              250 :
              0
          }, 100);

          // rotate
          $rotate.toggleClass('icon-rotate');
        });
      });
    }
  };

})(jQuery);
