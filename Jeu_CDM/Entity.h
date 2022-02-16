#define EMPTY	0
#define PLAYER	1
#define ENEMY	2

class Entity
{
public:
	Entity();
	~Entity();

	int getType();
	void setType(int);

private:
	int type = EMPTY;
};
