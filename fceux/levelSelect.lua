playStateAddress = 0x0048
selectLevelAddress = 0x0766

function playLevel(level)
  joypad.set(1, { start = true });
  for i = 1, 4 do
    emu.frameadvance();
  end
  local x = level % 10;
  local shouldPressA = level > 10;
  while true do
    local now = memory.readbyteunsigned(selectLevelAddress);
    if now == x then
      break;
    elseif now < 5 then
      joypad.set(1, { down = true });
    elseif now < x then
      joypad.set(1, { right = true });
    else
      joypad.set(1, { left = true });
    end
    emu.frameadvance();
    emu.frameadvance();
  end
  joypad.set(1, { A = shouldPressA });
  emu.frameadvance();
  joypad.set(1, { A = shouldPressA, start = true });
  emu.frameadvance();
  while memory.readbyteunsigned(playStateAddress) ~= 1 do
    emu.frameadvance();
  end
end
