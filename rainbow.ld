SECTIONS
{
  .text : {
    . =  0; *(.text.Purple);

    . = 0x10; *(.text.Olive);
    . = 0x20; *(.text.Lime);
    . = 0x30; *(.text.Maroon);
    . = 0x40; *(.text.Navy);
  }
  .data : {
    *(.data);
    *(.data.*);
    *(.rodata);
    *(.rodata.*);
    *(.bss);
  }
  .text : {
    wrist = .;
    . = wrist + 0; *(.text.Fuchsia);  

    . = wrist + 0x10; *(.text.Yellow);       
    . = wrist + 0x20; *(.text.Green);        
    . = wrist + 0x30; *(.text.Red);          
    . = wrist + 0x40; *(.text.Blue);         
    . = wrist + 0x50;
  }
}

