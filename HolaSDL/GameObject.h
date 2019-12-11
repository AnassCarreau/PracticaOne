#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_


class GameObject
{
	public:
		virtual void  render()=0;
		virtual	void update()=0 ;
		virtual ~GameObject() {};
		
};
#endif

