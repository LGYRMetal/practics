<?php
function lgy_setup() {
    /*
     * Let WordPress manage the document title.
     * By adding theme support, we declare that this theme does not use a
     * hard-coded <title> tag in the document head, and expect WordPress to
     * provide it for us.
     */
    add_theme_support('title-tag');
}
add_action('after_setup_theme', 'lgy_setup');

// close the xml-rpc
add_filter('xmlrpc_enabled', '__return_false');

// remove admin bar from my theme
show_admin_bar(false);
?>
