<?php

/**
 * @file
 * Template for the embedded view mode. Basesd on default node template.
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hides comments and links.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
  <?php if (isset($edit_link)) : ?>
    <p><?php print render($edit_link); ?></p>
  <?php endif; ?>
</div>
