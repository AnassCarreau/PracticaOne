#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_


class GameObject
{
	protected:
		virtual void  render()=0 ;
		virtual	void update()=0 ;
		virtual ~GameObject() ;
};
#endif

