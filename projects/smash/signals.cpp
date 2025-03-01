#include <iostream>
#include <signal.h>
#include "signals.h"
#include "Commands.h"

using namespace std;

void ctrlCHandler(int sig_num) {
 /* SmallShell&smash=SmallShell::getInstance();
  pid_t currProcess=smash.getCurrentProcess();
  std::cout<<" smash: got ctrl-c"<<std::endl;
  if(currProcess!=-1){
    //forefground running process
    if(kill(currProcess,SIGKILL)==-1){
      perror("smash error kill failed");
      return;
    }
    else{
      std::cout<<"smash: process "<< currProcess <<" was killed"<<std::endl;

    }
  }*/
  std::cout<<"smash: got ctrl-C"<<std::endl;
  SmallShell& smash = SmallShell::getInstance();
  pid_t currentProcess = smash.getCurrentProcess();
  if(currentProcess > 0){
    if(kill(currentProcess,SIGKILL) == -1){
      perror("smash error: kill failed");
      return;
  }
  JobsList*jobs=smash.getJobList();
  smash.removeJob(jobs->getJIDByPID(currentProcess));
  std::cout<<"smash: process "<<currentProcess<<" was killed"<<std::endl;
  }
  return;

}

void alarmHandler(int sig_num) {
  // TODO: Add your implementation
}