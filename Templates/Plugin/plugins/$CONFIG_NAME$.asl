# THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ARGO AI, LLC ("ARGO"),
# AND MAY NOT BE COPIED, REPRODUCED, MODIFIED, OR DISTRIBUTED WITHOUT
# ARGO'S PERMISSION.
# Copyright (c) 2018 Argo AI, LLC.

import Config.Config
import Config.ConfigReference

namespace(Argo.AutonomyIntegrationTools)

@access(read=public, write=public)
@minimum_version(0)
class $CONFIG_NAME$(Argo.Config.Config @0):
