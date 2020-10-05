#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main()
{
    int
    year   = 20,
    month  = 10,
    day    = 2,
    hour   = 16,
    minute = 0,
    second = 0;

    timeval tv;

    gettimeofday(&tv, NULL);
    time_t t_cur = tv.tv_sec;
    tm* lt = localtime(&t_cur);
    std::cout << "\nLocal date and time is: "
              << asctime(lt);

    tm time = {
        .tm_sec   = second,
        .tm_min   = minute,
        .tm_hour  = hour + 1,
        .tm_mday  = day,
        .tm_mon   = month - 1,
        .tm_year  = year - 1900,
        .tm_wday  = 0,
        .tm_yday  = 0,
        .tm_isdst = 0
    };

    if (time.tm_year < 0)
    {
        time.tm_year = 0;
    }

    tv.tv_sec = mktime(&time);
    tv.tv_usec = 0;

    if (settimeofday(&tv, NULL) < 0)
    {
        std::cerr << "Error setting the new time"
                  << std::endl;
    }

    gettimeofday(&tv, NULL);
    time_t t_new = tv.tv_sec;
    lt = localtime(&t_new);
    std::cout << "New date and time is: "
              << asctime(lt);

    tv.tv_sec = t_cur;
    tv.tv_usec = 0;

    if (settimeofday(&tv, NULL) < 0)
    {
        std::cerr << "Error setting the previus time"
                  << std::endl;
    }

    gettimeofday(&tv, NULL);
    t_cur = tv.tv_sec;
    lt = localtime(&t_cur);
    std::cout << "Restored date and time is: "
              << asctime(lt)
              << std::endl;

    std::cout << "Press any Key" 
    << std::endl;
    
    getchar();

    return EXIT_SUCCESS;
}
