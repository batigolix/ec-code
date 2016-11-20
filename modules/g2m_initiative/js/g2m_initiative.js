/**
 * @file
 * Provides custom behaviour for the go to market view.
 */

(function ($) {
  Drupal.behaviors.g2m_initiative = {
    attach: function (context, settings) {
      jQuery(".views-field-g2m-description .field-content").each(function() {
        var item = jQuery(this);
        if (item.outerHeight() > 135) {
          item.height(140);
          item.css({
            overflow : "hidden",
            position : "relative",
          })
          var div = jQuery('<div></div>');
          div.html(Drupal.t('Read more'));
          div.addClass("readmoreExpander");
          div.ref = item;
          div.click(function() {
            jQuery(this).parent().css({
              height: "auto",
            });
            jQuery(this).remove();
          });
          item.append(div);
        }
      });
    }
  };
})(jQuery);
