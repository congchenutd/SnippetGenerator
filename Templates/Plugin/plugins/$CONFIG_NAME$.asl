# THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ARGO AI, LLC ("ARGO"),
# AND MAY NOT BE COPIED, REPRODUCED, MODIFIED, OR DISTRIBUTED WITHOUT
# ARGO'S PERMISSION.
# Copyright (c) $YEAR$ Argo AI, LLC.

import Config.Config
import Config.ConfigReference

namespace($NAMESPACE_ONE_LINE_SEPARATED_BY_DOT$)

@access(read=public, write=public)
@minimum_version(0)
class $CONFIG_NAME$ (Argo.Config.Config @0):
