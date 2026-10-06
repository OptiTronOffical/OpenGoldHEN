/*
 * settings.c - the settings flags toggled through the command handler.
 */

#include <goldhen/types.h>

/* set_aio_fix_plugin_flag @ 0x10218d size=14 */
void set_aio_fix_plugin_flag(u64 *param_1)

{
  g_aio_fix_plugin_flag = (int)*param_1;
  return;
}

/* set_game_patch_plugin_flag @ 0x10217f size=14 */
void set_game_patch_plugin_flag(u64 *param_1)

{
  g_game_patch_plugin_flag = (int)*param_1;
  return;
}

/* set_game_update_module_flag @ 0x102163 size=14 */
void set_game_update_module_flag(u64 *param_1)

{
  g_game_update_module_flag = (int)*param_1;
  return;
}

/* set_patch_update_module_flag @ 0x102171 size=14 */
void set_patch_update_module_flag(u64 *param_1)

{
  g_patch_update_module_flag = (int)*param_1;
  return;
}
