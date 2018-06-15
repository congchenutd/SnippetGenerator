# THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ARGO AI, LLC ("ARGO"),
# AND MAY NOT BE COPIED, REPRODUCED, MODIFIED, OR DISTRIBUTED WITHOUT
# ARGO'S PERMISSION.
# Copyright (c) $YEAR$ Argo AI, LLC.

import Config.Config
import Config.ConfigReference

namespace($NAMESPACE_DOT$)

@access(read=public, write=public)
@minimum_version(1)
class $CONFIG_NAME$ (Argo.Config.Config @0):
  test = bool(true) @1