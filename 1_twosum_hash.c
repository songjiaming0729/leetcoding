#include <uthash.h>
#include <stdio.h>


typedef struct jaminhash
{
    int user_id;
    int user_key;
    UT_hash_handle hh;
}jmhash;

jmhash* users = NULL;

jmhash* find_hash(int user_id)
{
    jmhash *s = NULL;
    HASH_FIND_INT(users, &user_id, s);
    return s;
}	

void add_hash(int user_id, int user_key)
{
    jmhash *s = find_hash(user_id);
    if(s==NULL)
    {
    	jmhash* tmp = malloc(sizeof(jmhash));
        tmp->user_id = user_id;
	tmp->user_key = user_key;
        HASH_ADD_INT(users, user_id, tmp);
    }
    else
    {
        s->user_key = user_key;
    }
}
int main()
{
    // users = NULL 很重要  在Leetcode上，会导致[3,3]过不去.
    printf("Hello world!!\n");
    
    int a[2] = {3,3};
    int target = 6;
    int a_len = sizeof(a)/4;
    int result = 0;
    for(int i=0; i<a_len; ++i)
    {
        
        result = target - a[i];
	jmhash *s = find_hash(result);
	if(s!=NULL)
	{
	    int b[2] = {0};
	    b[0] = s->user_key;
	    b[1] = i;
	    printf("0_id:%d 1_id:%d \n", b[0], b[1]); 
	}
	  
	add_hash(a[i], i);

    }
    return 0;
}
