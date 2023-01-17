#include "TestEntity.h"


TestEntity::TestEntity(){}
TestEntity::~TestEntity(){}
void TestEntity::OnDraw()
{
	Draw(player.GetDrawable());
	if(player.IsAttack())
		Draw(player.GetDrawableProjectile());
	Draw(monster.GetDrawable());
	if (monster.IsAttack())
		Draw(monster.GetDrawableProjectile());
}
void TestEntity::OnUpdate()
{
	player.OnUpdate();
	monster.OnUpdate();

}