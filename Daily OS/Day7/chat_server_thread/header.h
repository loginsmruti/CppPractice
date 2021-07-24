
struct Msg
{
	int i;
	char data[80];
	int id,fid;
};

struct myMsg
{
	long mtype;
	struct Msg m;
};
