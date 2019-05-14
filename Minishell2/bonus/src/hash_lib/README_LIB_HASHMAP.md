//README.md

//CREATE HASHMAP
hashmap_t *hashmap = hm_create(64000);

//FILL NEW ENV WITH HASHMAP
my_env = fill_env_with_hashmap(hashmap, env);

//FILL HAHSMAP WITH CHAR** ENV
hashmap = fill_hashmap_with_env(hashmap, env)

//REPLACE SPECIAL CASE
my_env = replace_case_hashmap(hashmap, "HOST", "LOL", my_env);

//DELETE SPECIAL CASE
my_env = delete_case_hashmap(hashmap, "HOST", my_env);

//ADD VALUE In HASH
my_env = add_value_to_env(hashmap, "TEST", "YOLO", my_env);

//PRINT TAB
print_tab(my_env);

// FREE/DESTROY
free_tab(my_env);
hm_destroy(hashmap);