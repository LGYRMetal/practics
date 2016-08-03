<?php
/**
 * Register our sidebars and widgetized areas.
 *
 */
/*
function mytheme_widgets_init() {

    register_sidebar(array(
        'name'          => __('Main sidebar', 'my-themes'),
        'id'            => 'sidebar-1',
        'before_widget' => '<div>',
        'after_widget'  => '</div>',
        'before_title'  => '<h2 class="rounded">',
        'after_title'   => '</h2>',
    ));
}
add_action('widgets_init', 'mytheme_widgets_init');
?>
 */
if ( function_exists('register_sidebar') )
    register_sidebar();
?>
