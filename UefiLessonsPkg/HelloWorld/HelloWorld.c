/*
 * Copyright (c) 2021, Konstantin Aladyshev <aladyshev22@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * EFI_HANDLE         gImageHandle = NULL;
EFI_SYSTEM_TABLE   *gST         = NULL;
EFI_BOOT_SERVICES  *gBS         = NULL;
*/

#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Protocol/ShellParameters.h> 

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS Status;
  EFI_SHELL_PARAMETERS_PROTOCOL* ShellParameters;

  Status = gBS->HandleProtocol(
    ImageHandle,
    &gEfiShellParametersProtocolGuid,
    (VOID **) &ShellParameters
  );
  gST->ConOut->OutputString(gST->ConOut, L"Hello World!\n");
  Print(L"Jai Jagannath");
  Print(L"Bye Bye!");

  if (Status == EFI_SUCCESS) {
    if (ShellParameters->Argc == 2) {
      Print(ShellParameters->Argv[1]);
    }
  }
  
  return EFI_SUCCESS;
}
