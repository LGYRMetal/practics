#drop table wordpress.wp_commentmeta;
#drop table wordpress.wp_comments;
#drop table wordpress.wp_links;
#drop table wordpress.wp_options;
drop table wordpress.wp_postmeta;
drop table wordpress.wp_posts;
drop table wordpress.wp_term_relationships;
drop table wordpress.wp_term_taxonomy;
drop table wordpress.wp_termmeta;
drop table wordpress.wp_terms;
drop table wordpress.wp_usermeta;
drop table wordpress.wp_users;

mysql -u root -p198708060316 -N -s information_schema -e "select concat('drop table if exists ', table_name, ';') from tables where table_schema='djangodb'" | mysql -u root -p198708060316 -f djangodb
