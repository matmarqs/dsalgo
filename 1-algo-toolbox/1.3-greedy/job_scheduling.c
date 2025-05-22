#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* generates random x, such that a <= x <= b */
int randint_between(int a, int b) {
    if (b < a) {
        int aux = a;
        a = b;
        b = aux;
    }
    return a + rand() % (b - a + 1);
}

typedef struct {
    int profit;
    int deadline;
} Job;

int cmp_jobs(const void *a, const void *b) {
    Job *ja = *(Job **) a;
    Job *jb = *(Job **) b;
    int cmp = ja->deadline - jb->deadline;
    if (cmp) {
        return cmp;
    }
    return ja->profit - jb->profit;
}

Job *job_schedule(Job **jobs) {
    return *jobs;
}

Job *job_create(int profit, int deadline) {
    Job *j = (Job *) malloc(sizeof(Job));
    j->profit = profit;
    j->deadline = deadline;
    return j;
}

void job_free(Job *j) {
    free(j);
}

void job_print(Job *job) {
    printf("(%d, %d) ", job->profit, job->deadline);
}

void print_all_jobs(Job **jobs, int num_jobs) {
    for (int i = 0; i < num_jobs; i++) {
        job_print(jobs[i]);
    }
    printf("\n");
}

void stress_test() {
    srand(0);

    int num_jobs = randint_between(1, 4);

    Job **jobs = (Job **) malloc(sizeof(Job *) * num_jobs);

    for (int i = 0; i < num_jobs; i++) {
        jobs[i] = job_create(randint_between(10, 200), randint_between(1, 10));
    }

    qsort(jobs, num_jobs, sizeof(Job *), cmp_jobs);

    print_all_jobs(jobs, num_jobs);

    for (int i = 0; i < num_jobs; i++) {
        free(jobs[i]);
    }
    free(jobs);
}

int main() {

    stress_test();

    return 0;
}

/*
Job *j0, *j1, *j2, *j3, *j4;
j0 = job_create(20, 1);
j1 = job_create(25, 1);
j2 = job_create(30, 2);
j3 = job_create(50, 2);
j4 = job_create(15, 3);

int num_jobs = 5;
Job **jobs = (Job **) malloc(sizeof(Job *) * num_jobs);


jobs[0] = j0;
jobs[1] = j1;
jobs[2] = j2;
jobs[3] = j3;
jobs[4] = j4;

qsort(jobs, num_jobs, sizeof(Job *), cmp_jobs);

print_all_jobs(jobs, num_jobs);
*/

/* 
 * let n be the number of jobs
 * 
 * let's examine the case where all jobs have deadline = 1
 * in this case, it's trivial that we choose the job with the most profit
 *
 * now let's examine the case where 2 jobs have deadline = 1
 * and 2 jobs have deadline = 2;
 *
 * [(50, 1), (200,1), (300,2), (100,2)]
 *
 * optimal choice -> (200,1) and (300,2)
 *
 * naive would give -> (300,2) and (100,2)
 *
 * primeiro ordenar por maior profit, e depois por menor deadline
 * daí excluimos os jobs que já tiverem passado da deadline
 *
 * (200, 2), (50, 1), (50, 1)
 *
 *
 * 
 * (50, 2), (30, 2), (25, 1), (20, 1), (15,3)
 *
 * (20, 1), (25, 1), (30, 2), (50, 2), (15, 3)
 *
 * (300, 1), (310, 2)
 *
 *
 *
 * let N be the largest profit with the latest job done on time t
 * the job on time t has to have the largest profit
 * if not, we could choose another job that would have a larger profit,
 * contradicting the fact that N is the largest one
 *
 * let m = max_(job \in jobs) deadline(job)
 *
 * */
