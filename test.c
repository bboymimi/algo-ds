#include<stddef.h>

typedef void (callback_fn_t)(void);

typedef struct cb_st {
	callback_fn_t user_fn;
	void * user_data;
} callback_t;

void do_callback(const callback_t * cb)
{

	((callback_fn_t) cb) (cb->user_data); /*** CRASHES ***/

}

void my_cb(void * data)
{
	printf("Hello, %s!\n", (char*) data);
}

void main()
{
	callback_t cb;
	cb.user_data = (void*) "Stephane";
	cb.user_fn = &my_cb;
	do_callback(&cb);
}
