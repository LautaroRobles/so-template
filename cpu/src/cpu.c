#include <commons/log.h>

t_log *logger;

int main(int argc, char *argv[])
{
    logger = log_create("cpu/logs/cpu.log", "cpu", true, LOG_LEVEL_TRACE);

    log_trace(logger, "Se ejecuto el modulo cpu con %i parametros", argc - 1);

    return 0;
}