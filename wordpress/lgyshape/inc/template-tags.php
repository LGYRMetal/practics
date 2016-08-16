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

/**
 * Returns true if a blog has more than 1 category
 *
 * @since ShapeLGY 1.0
 */
function shape_categorized_blog() {
    if ( false === (
        $all_the_cool_cats = get_transient( 'all_the_cool_cats' ) ) ) {
        // Create an array of all the categories that are attached to posts
        $all_the_cool_cats = get_categories( array(
            'hide_empty' => 1,
        ) );

        // Count the number of categories that are attached to the posts
        $all_the_cool_cats = count( $all_the_cool_cats );

        set_transient( 'all_the_cool_cats', $all_the_cool_cats );
    }

    if ( '1' != $all_the_cool_cats ) {
        // This blog has more than 1 category so shape_categorized_blog
        // should return true
        return true;
    }
    else {
        // This blog has only 1 category so shape_categorized_blog should
        // return false
        return false;
    }
}

/**
 * Flush out the transients used in shape_categorized_blog
 *
 * @since ShapeLGY 1.0
 */
function shape_category_transient_flusher() {
    // Like, beat it. Dig?
    delete_transient( 'all_the_cool_cats' );
}
add_action( 'edit_category', 'shape_category_transient_flusher' );
add_action( 'save_post', 'shape_category_transient_flusher' );

if ( ! function_exists( 'shape_content_nav' ) ) :
/**
 * Display navigation to next/previous pages when applicable
 *
 * @since ShapeLGY 1.0
 */
function shape_content_nav( $nav_id ) {
    global $wp_query, $post;

    // Don't print empty markup on single pages if there's nowhere to
    // navigate.
    if ( is_single() ) {
        $previous = ( is_attachment() ) ?
                    get_post( $post->post_parent ) :
                    get_adjacent_post( false, '', true );
        $next = get_adjacent_post( false, '', false );

        if ( ! $next && ! $previous )
            return;
    }

    // Don't print empty markup in archives if there's only one page.
    if ( $wp_query->max_num_pages < 2 && ( is_home() ||
                                           is_archive() ||
                                           is_search() ) )
        return;
}
endif; // shape_content_nav
