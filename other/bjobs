#!/usr/bin/perl
#
# Usage: bjobs [[-u] uname]
#
$version=0.7;

use File::stat;
use Term::ANSIColor;

$maxnode=7;

$bjobs=$0;
$bjobs =~ s/.*\///g;

#@pool=split('=',`/bin/cat /usr/local/pbs/bin/nhpcctimer/nhpcctimer.config | /bin/grep POOLREBOOT`);

$poolreboot=$pool[1];

#print "bjobs, v" . $version . ", by ZLB. Type \"$bjobs -h\" for help!\n\n";
#print "\33[33;1;5mPool Reboot Period (days): $poolreboot";
#print "\33[0;0m";


#print color('bold green on_blue');
#print "WARNING: this process may be dead\n";
#print color('bold red on_blue');
#print "WARNING: Memory Allocation is too large ( > 1 GB )\n";
#print color('bold yellow on_blue');
#print "WARNING: Net Flow I/O is too large ( > 2000 KBytes/s )\n\n";
print color('reset');

#$netflow=`/bin/grep \"storage\" /people/opt/nfs.log | /bin/awk '{print \$2\" \"\$3}'`;
#$netflow=~ s/\n//g;
#@tmp=split(" ",$netflow);
#print "*********************************************************************************************************************\n";
#print "       NFS Storage I/O Net Flow:  $tmp[0] kbytes/s incoming, $tmp[1] kbits/s outgoing\n";

#$netflow=`/bin/grep \"node1\" /people/opt/nfs.log | /bin/awk '{print \$2\" \"\$3}'`;
#$netflow=~ s/\n//g;

@tmp=split(" ",$netflow);
#print "       node1 I/O Net Flow:       $tmp[0] kbytes/s incoming, $tmp[1] kbits/s outgoing\n";
#print "*********************************************************************************************************************\n";
#print "\n";

$pbsqstat="sudo /opt/gridview/pbs/dispatcher/bin/qstat";
$loadinfo_dir="/usr/local/loadinfo";
$nodes_dir="/usr/local/nodes";

$uname='';
$verbose=1;
$netflow=0;
$i=0;
while ($i<@ARGV) {
    $opt=substr($ARGV[$i],0,2);
    if     ($opt eq '-h') {
	usage();
    } elsif ($opt eq '-u') {
	$uname eq '' or usage();
	if ( $opt eq $ARGV[$i] ) {
	    $i<@ARGV-1 or usage();
	    $uname=$ARGV[++$i];
	} else {
	    $uname=$ARGV[$i];
	    $uname=~ s/^$opt//;
	}
    } elsif ($opt eq '-q') {
	$verbose=0;
    } elsif ($opt eq '-v') {
	$verbose=1;
    } elsif ($opt eq '-d') {
	$detail=1;
    } elsif ($opt eq '-n') {
	$netflow=1;
    } else {
	$uname eq '' or usage();
	$uname=$ARGV[$i];
    }
    ++$i;
}
#$uname ne '' or $uname=getpwuid($>);
$uname ne '' or $uname='all';

    if ($detail ne 1){
        print color('bold yellow');
        print "'bjobs JOBID -d' or 'bjobs -d' for details! ";
        print color('reset');
    }
    if ($detail eq 1){
        print color('bold yellow');
#        print"'SHARE=No', CPU load near 100% (>70% at least); 'SHARE=Yes', CPU load near 50%. Otherwise, Check Your Job!";
        print"If one of CPU loads is always equal to 0.0%, Check Your Job!";        
        print color('reset');
    }
print "\n";

# First, get load averages
#open(INPUT, "(cd $loadinfo_dir; grep . *) |");
#while (!eof(INPUT)) {
#    $line=<INPUT>; chomp($line);
#    @fields=split(':', $line);
#    $no=$fields[0];
#    @fields=split(' ', $fields[1]);
#    $loads{"$no"}=$fields[0];
#    if ( stat($nodes_dir . "/" . $no) ) {
#	;
#    } else {
#	$loads{"$no"}="0.00";
#    }
#    if (! $fields[3] eq "") {
#	$flops{"$no"}=normalize_flops($fields[3]);
#	if (! $fields[4] eq "") {
#	    $flops{"$no"}=$flops{"$no"} . " " . normalize_flops($fields[4]);
#	}
#    } else {
#	$flops{"$no"}="";
#    }
#}
#close(INPUT);
#$fmt="%-7s%-6s%-8s%-4s%-8s%-11s%-2s%-10s%-7s%-7s%-13s%-8s%-10s\n";
$fmt="%-10s%-10s%-10s%-4s%-8s%-11s%-2s%-12s%-7s%-7s%-13s%-8s\n";
if ( $netflow eq 0 ) {
#   printf $fmt,"USER","JOBID","JOBNAME","NP","QUEUE","ELAP.TIME","S","NODE",
#  	       "CPU(\%)", "MEM(\%)", "COMMAND", "PID", "UPTIME";
   printf $fmt,"USER","JOBID","JOBNAME","NP","QUEUE","ELAP.TIME","S","NODE(cores)",
  	       "CPU(\%)", "MEM(\%)", "COMMAND", "UPTIME";  	       
}
else {
#   printf $fmt,"USER","JOBID","JOBNAME","NP","QUEUE","ELAP.TIME","S","NODE",
#	       "CPU(\%)", "MEM(\%)", "NET I/O (KBYTE)", "PID", "UPTIME";
   printf $fmt,"USER","JOBID","JOBNAME","NP","QUEUE","ELAP.TIME","S","NODE(cores)",
	       "CPU(\%)", "MEM(\%)", "NET I/O (KBYTE)", "UPTIME";	       
}
printf $fmt,"-----","-----","-------","--","-----","---------","-","-------",
	    "------", "------", "-----------","--------";

open(PBS_INPUT, "$pbsqstat -f |");
$line="";
$job{'jobid'}="";
while (1) {
    if ( $line eq "" ) {
	last if (eof(PBS_INPUT));
	$line=<PBS_INPUT>; chomp($line); $line =~ s/^ *//; $line =~ s/ *$//;
    }
    if ( substr($line,0,7) eq "Job Id:" ) {
	printjob() if ( $job{'jobid'} ne "" );
	%job=(  "user","", "jobid","", "queue","", "jobname","", "np","",
		"etime","", "mode","", "node",""  );
	@tmp = split(': ', $line);
	$job{'jobid0'}=$tmp[1];
	$job{'jobid'}=$tmp[1];
	$job{'jobid'}=~ s/\..*$//g;
	$line="";
	next;
    }
    @tmp = split(' = ', $line);
    if (eof(PBS_INPUT)) {
	$line = "";
    } else {
	while (!eof(PBS_INPUT)) {
	    $line=<PBS_INPUT>; chomp($line); $line =~ s/^ *//; $line =~ s/ *$//;
	    last if ( substr($line,0,1) ne "\t" );
	    $line=substr($line,1);
	    $tmp[1] = $tmp[1] . $line;
	}
    }
    SWITCH: {
	if ($tmp[0] eq "Job_Owner") {
	    $job{'user'}=$tmp[1];
	    $job{'user'}=~ s/\@.*$//g;
	    last SWITCH;
	}
	if ($tmp[0] eq "Job_Name") {
	    $job{'jobname'}=substr($tmp[1],0,14);$tmp[1];
	    last SWITCH;
	}
	if ($tmp[0] eq "queue") {
	    $job{'queue'}=$tmp[1];
	    last SWITCH;
	}
	if ($tmp[0] eq "Resource_List.nodect") {
	    @tmp1=split(':', $tmp[1]);
	    $job{'np'}=$tmp1[0];
	    last SWITCH;
	}
	if ($tmp[0] eq "Resource_List.nodes") {
	    $jobreq=$tmp[1];
	    last SWITCH;
	}
	if ($tmp[0] eq "resources_used.walltime") {
	    $job{'etime'}=$tmp[1];
	    last SWITCH;
	}
	if ($tmp[0] eq "job_state") {
	    $job{'mode'}=$tmp[1];
	    last SWITCH;
	}
	if ($tmp[0] eq "exec_host") {
	    $job{'node'}=$tmp[1];
	    last SWITCH;
	}
    }
}
close(PBS_INPUT);
printjob() if ( $job{'jobid'} ne "" );

sub printjob () {
    local($flag, $n, $no);
    if ($detail eq 1){
	$pbsnodes=`pbsnodes -a`;
    }    

# if you only want to display the jobs in your account, recover the following commands. by zhuangjun          
#    if ($uname eq '') {
#	$uname='all';
#    }
	$uname eq 'all' or $uname eq 'ALL' or $uname eq 'All' or
        $uname eq $job{"user"} or $uname eq $job{"jobid0"} or
        $uname eq $job{"jobid"} or $uname eq $fields[0] or return;
	  
    $job{'node'}='' if ( $job{'mode'} eq 'Q' );
    

    $flag=0;
    if ( $job{'node'} eq "" ) {    
	$corereq=0;
	$maxpnode=0;
	$jobreq=~ s/Resource_List.nodes =//g;
	$jobreq=~ s/ppn=//g;
	foreach $nreq (split('\+',$jobreq)) {
	    @reqtmp=split(':',$nreq);
	    $nnode=$reqtmp[0];
	    $ncore=$reqtmp[1];
	    if ($nnode =~ m/node/) {
		$nnode=1;
	    }
	    if ($ncore eq "") {
		$ncore=1;
	    }
	    $corereq=$corereq+$nnode*$ncore;
	    if ($ncore > $maxpnode) {
		$maxpnode=$ncore;
	    }
	}
	$resreq="(".$corereq."/".$maxpnode.")";
	printf $fmt, $job{'user'}, "$job{'jobid'}", $job{'jobname'},
		$job{'np'}, $job{'queue'}, "--", $job{'mode'},
		$resreq, "--", "--", "--";
	return;
    } 
    $avload=0;
    for ($pass=0; $pass < 2; ++$pass) {
	# pass 0: compute average load, pass 1: print results
	$lastnode="";
	foreach $n (split('\+',$job{'node'})) {
	    $n=~ s/\/[0-9][0-9]*//g;
	    if ($pass == 0) {
		$core{$job{'jobid'}.$n}++;
	    }
            $nodenumber=$n;            
            $nodenumber=~ s/node//g;    
	    ( $lastnode eq $n ) and next;
	    $lastnode=$n;
	    if ($pass == 0) {
		$avload += $loads{"$n"};
		next
	    }
	    $load=$loads{"$n"};
	    if ($load < 0.1) {
		print color('red');
	    } elsif ($load < 0.75*$avload) {
		print color('magenta');
	    } elsif ($load > 1.25*$avload) {
		print color('green');
	    }
	    $node_name=$n."(".$core{$job{'jobid'}.$n}.")";
            if ( $detail eq 1 ) {
                $load='';
                $mem='';
                $cmd='';
                $shareuser='';
                $uptime='';
                $jobpid='';
		foreach $nodestat (split('\n\n',$pbsnodes)){
                    @content=split('\n',$nodestat);
                    if ($content[0] eq $n){
                        @stattmp=split(' = ',$content[1]);
                        @nptmp=split(' = ',$content[2]);
                        if (($stattmp[1] eq "job-exclusive")&&($nptmp[1] eq "2")){
                            $sharetmp1="Yes: ";
                        }
                        else {
                            $sharetmp1="No, ";
                        }
                    }
                }
  	    	if ( ($nodenumber >= 0) && ($nodenumber <= $maxnode) ) {
      			$getinfo=`/usr/bin/ssh $n /home/wangyin/bin/getinfo.pl -i $job{'jobid'} $job{'user'}`;
     	   	}		
      	    	else {
    			$getinfo='';
   		}
################################################################
#	    if ( ($nodenumber >= 0) && ($nodenumber <= $maxnode) ) {
#                $infotmp=`snmpget -v2c -c public $n .1.3.6.1.4.1.4553.100.2.1.0`;
#		        $infotmp=`ssh $n top -n 1 -b | grep $job{'user'}`;
#            } 
#            else {
#                $infotmp='';
#            } 
#	    @keyinfo=split('\n',$infotmp);
#            @eachinfo1=split(' ',$keyinfo[0]);
#            @eachinfo2=split(' ',$keyinfo[1]);
#	          $load=$eachinfo1[8];
#            $mem=$eachinfo1[9];
#            $cmd=$eachinfo1[12];
#	    $sharetmp2=$eachinfo2[12]."(".$eachinfo2[8]."%)";
#	    $shareuser=$sharetmp1.$sharetmp2;
########Default settings, for full information##################
###############need snmp and OID################################
#            @snmpinfo=split('"',$infotmp);
#            foreach $eachinfo (split('::\.',$snmpinfo[1])) {
#               if ( index($eachinfo,$n,0) eq -1) {
#                  if ( index($eachinfo,'days',0) ne -1 ) {
#                     @uptimeinfo=split('days',$eachinfo);
#                     if ( $uptimeinfo[0] < $poolreboot ) {
#                        $uptime=$eachinfo;
#                     }
#                     else {
#                        $uptime="\33[33;1;5mPool Reboot";
#                     }
#                  }
#                  elsif ( index($eachinfo,"FreeTime, ",0) ne -1 ) {
#                  }
#                  else {
#                     @eachproc=split('::',$eachinfo);
#                     if ($eachproc[1] == $job{'jobid'} ) { 
#                        $load=$eachproc[2];
#                        $mem=$eachproc[3];
#                        if ( $netflow eq 0 ) {
#                           $cmd=$eachproc[4];
#                        }
#                        else {
#                           $cmd=`/bin/grep \"$n \" /people/opt/nfs.log | /bin/awk '{print \$2\" \"\$3}'`;
#                           $cmd=~ s/\n//g;
#                        }
#                     }
#                     else {
#                        if (index($eachproc,'days',0) eq -1) {
#                           $shareuser=$eachproc[0];
#                        }
#                    }
#                  }
#               }
#            }
#################################################################
		if ($getinfo eq '') {
		   print color('green');
		   if ( ! $flag ) {
#                        printf $fmt, $job{'user'}, "$job{'jobid'}", $job{'jobname'},
#                        $job{'np'}, $job{'queue'}, $job{'etime'}, $job{'mode'},
#                        $node_name, $load, $mem, $cmd, $jobpid, $uptime;
                        printf $fmt, $job{'user'}, "$job{'jobid'}", $job{'jobname'},
                        $job{'np'}, $job{'queue'}, $job{'etime'}, $job{'mode'},
                        $node_name, $load, $mem, $cmd, $uptime;                        
                        print color('reset');
                        $flag = 1;
                   }
                   else {
#                        printf $fmt, '', '', '', '', '', '', '',
#                        $node_name, $load, $mem, $cmd, $jobpid, $uptime;
                        printf $fmt, '', '', '', '', '', '', '',
                        $node_name, $load, $mem, $cmd, $uptime;                        
                        print color('reset');
                   }
		}
		$flag_core=1;
	   	foreach $job (split('\n',$getinfo)) {
           	   @jobinfo=split(' ',$job);
           	   $load=$jobinfo[1];
           	   $mem=$jobinfo[2];
           	   $uptime=$jobinfo[3];
           	   $cmd=$jobinfo[4];
           	   $jobpid=$jobinfo[0];
	   	   if($flag_core) {
		   	 $flag_core=0;
	  	   }
	   	   else {
		    	$node_name="";
	 	   }
           	   if ( ($nodenumber >= 0) && ($nodenumber <= $maxnode) ) {
		    	print color('red');
             	  	if ( $mem > 1000000 ) {
                  	    print color('bold red on_blue');
              	   	}
               	   	@tmp = split(' ', $cmd);
               	   	if ( ( $tmp[0] > 2000 ) || ( $tmp[1] > 2000 ) ) {
                  	    print color('bold yellow on_blue');
                  	}             
               	  }
               	  if ( ! $flag ) {
#               	   	printf $fmt, $job{'user'}, "$job{'jobid'}", $job{'jobname'},
#                   	$job{'np'}, $job{'queue'}, $job{'etime'}, $job{'mode'},
#                   	$node_name, $load, $mem, $cmd, $jobpid, $uptime;
               	   	printf $fmt, $job{'user'}, "$job{'jobid'}", $job{'jobname'},
                   	$job{'np'}, $job{'queue'}, $job{'etime'}, $job{'mode'},
                   	$node_name, $load, $mem, $cmd, $uptime;                   	
                   	print color('reset');
                   	$flag = 1;
                   }
               	   else {
		  	printf $fmt, '', '', '', '', '', '', '',
#                   	$node_name, $load, $mem, $cmd, $jobpid, $uptime;
                   	$node_name, $load, $mem, $cmd, $uptime;                   	
                   	print color('reset');
             	   }
      	       }
	    }
            

	    else{
	        if ( ! $flag ) {    	 
		    printf $fmt, $job{'user'}, "$job{'jobid'}", $job{'jobname'},
		    $job{'np'}, $job{'queue'}, $job{'etime'}, $job{'mode'},
		    $node_name, $load, $mem, $cmd, $shareuser, $uptime;
                    print color('reset');
		    $flag = 1;
	        } 
	        else {
		    printf $fmt, '', '', '', '', '', '', '',
		    $node_name, $load, $mem, $cmd, $shareuser, $uptime;
                    print color('reset');
	    	}
	    }
    	}
	#$avload/= $job{'np'};
    }
}

sub usage () {
    print "Usage:\n";
    print "    $bjobs [options] [user_name|all] [job_id]\n";
    print "Options:\n";
    print "    -u user_name\tDisplay information about jobs of a user\n";
    print "    -u all      \tDisplay information about all jobs\n";
    print "    -q          \tQuiet\n";
    print "    -v          \tVerbose\n";
    print "    -d          \tProcess Info\n";
    print "    -n          \tNet Flow I/O Info\n";
    print "    -h          \tHelp\n";
    exit;
}

sub normalize_flops () {
    local $flops, $suffix, $str;

    $flops = $_[0];

    if ($flops < 0.00001) {
	return "0.000";
    }

    $suffix = "M";
    if ($flops < 0.1) {
	$suffix = "K";
	$flops = $flops * 1000;
    } elsif ($flops >= 100) {
	$suffix = "G";
	$flops = $flops / 1000;
    }
    $str = sprintf($flops <= 9.995 ? "%4.02f%s" : "%4.3g%s", $flops, $suffix);
    #
    # Change 'xx[KMG]' to 'xx.0[KMG]'
    if (substr($str, 0, 2) eq "  " && index($str, '.') < 0) {
	$str = substr($str, 2, 2) . ".0" . $suffix;
    }
    return $str;
}
