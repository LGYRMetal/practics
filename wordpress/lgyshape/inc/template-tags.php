<?php
/**
 * Custom template tags for this theme.
 *
 * Eventually, some of the functionality here could be replaced by core
 * features
 *
 * @package ShapeLGY
 * @since ShapeLGY 1.0
 */

if ( ! function_exists( 'shape_posted_on' ) ) :
/**
 * Prints HTML with meta information for the current post-date/time and
 * author.
 *
 * @since ShapeLGY 1.0
 */
function shape_posted_on() {
    printf( __(
        'Posted on <a href="%1$s" title="%2$s" rel="bookmark">' .
        '<time class="entry-date" datetime="%3$s" pubdate>%4$s</time></a>' .
        '<span class="byline"> by <span class="author vcard">' .
        '<a class="url fn n" href="%5$s" title="%6$s" rel="author">' .
        '%7$s</a></span></span>',
        'shape' ),
    esc_url( get_permalink() ),
    esc_attr( get_the_time() ),
    esc_attr( get_the_date( 'c' ) ),
    esc_html( get_the_date() ),
    esc_url( get_author_posts_url( 'ID' ) ),
    esc_attr( sprintf( __( 'View all posts by %s', 'shape' ),
                       get_the_author() ) ),
    esc_html( get_the_author() ) );
}
endif;
