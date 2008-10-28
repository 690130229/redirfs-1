#ifndef __RFSCTL_H__
#define __RFSCTL_H__

#define RFSCTL_PATH_INCLUDE	1
#define RFSCTL_PATH_EXCLUDE	2

struct rfsctl_path {
	int type;
	int id;
	char *name;
};

struct rfsctl_filter {
	struct rfsctl_path **paths;
	char *name;
	int priority;
	int active;
};

struct rfsctl_filter *rfsctl_get_filter(const char *name);
void rfsctl_put_filter(struct rfsctl_filter *filter);
struct rfsctl_filter **rfsctl_get_filters(void);
void rfsctl_put_filters(struct rfsctl_filter **filters);
int rfsctl_add_path(const char *name, const char *path, int type);
int rfsctl_rem_path(const char *name, int id);
int rfsctl_del_paths(const char *name);
int rfsctl_unregister(const char *name);
int rfsctl_activate(const char *name);
int rfsctl_deactivate(const char *name);

#endif

