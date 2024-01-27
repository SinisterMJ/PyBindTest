#if defined(__cplusplus)
extern "C" {
#endif /* SUB_LIC || RENESAS_SH || __cplusplus */

typedef short line;

typedef struct 
{
        line      lineDat[1000];
} shortLine;

typedef struct {
    int Count;
    short* data;
    short* timestamps;
    shortLine* lineData[3];
} Container;

int add_external(int left, int right);

#if defined(__cplusplus)
}
#endif /* SUB_LIC || RENESAS_SH || __cplusplus */