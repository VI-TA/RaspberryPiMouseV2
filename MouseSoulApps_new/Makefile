COMPILER  = g++
CFLAGS    = -std=c++11 -g -MMD -MP -Wall -Wextra -Winit-self -Wno-missing-field-initializers -lpthread
INCLUDE   = -I./MouseSoulApps -I./FunctionNode -I./EventRouter -I./EventContainer
TARGET    = ./bin/MouseSoulApps
#LIBS = $(wildcard ./bin/*.a)

# リンクの順序は依存関係に考慮して定義すること。
LIBS = ./obj/MouseSoulApps.a ./obj/FunctionNode.a ./obj/EventContainer.a ./obj/EventRouter.a

$(TARGET): $(LIBS)
	$(COMPILER) -o $@ $^ $(CFLAGS) $(INCLUDE)

clean:
	-rm -f $(LIBS) $(TARGET)
