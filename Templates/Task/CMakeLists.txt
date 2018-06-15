argo_add_schema(TARGET  $CONFIG_NAME$
				SCHEMAS TaskConfig
                SOURCES $CONFIG_NAME$.asl
                        $CONFIG_NAME$.cc
                LIBS    Config
                )

argo_add_executable(TARGET  $COMPONENT_NAME$
  					SCHEMAS $CONFIG_NAME$
  					SOURCES $COMPONENT_NAME$.cc 
  					LIBS    ErrorHandling
          					Task
)