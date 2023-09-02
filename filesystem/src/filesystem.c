#include <commons/log.h>

t_log *logger;

int main(int argc, char *argv[])
{
    logger = log_create("filesystem/logs/filesystem.log", "filesystem", true, LOG_LEVEL_TRACE);

    log_trace(logger, "Se ejecuto el modulo filesystem con %i parametros", argc - 1);

    return 0;
}