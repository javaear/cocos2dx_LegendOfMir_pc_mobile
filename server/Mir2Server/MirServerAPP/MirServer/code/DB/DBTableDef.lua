tableDef =
{
	data_account = {aid='number', account='string', password='string', primary_key='aid'},
	data_actor = {pid='number', aid='number', name='string', level='number',
		style='number',sex='number',item='table',gold='number',money='number',
		equip='table',worldid='number',worldpos='table', primary_key='pid'},
	data_item = {pid='number', itemid='number', typeid='number',count='number', isEquip='number', gridIndex="number", primary_key='itemid'},
	data_skill = {skillid="number",pid="number",level="number",exc="number", primary_key='id'}
}
