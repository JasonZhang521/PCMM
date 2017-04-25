
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
main(int argc,char *argv[])
{
 struct passwd *srcc_pwd;
 char *proc_name = "sudo /opt/gridview/pbs/dispatcher/bin/qstat -a");

 gid_t srcc_gid;
 uid_t srcc_uid;
 int gg,uu;

 srcc_pwd=getpwnam("root");
 srcc_gid=srcc_pwd->pw_gid;
 srcc_uid=srcc_pwd->pw_uid;
 gg=setgid(srcc_gid);
 uu=setuid(srcc_uid);
 gg=system(proc_name);

 return;
}
