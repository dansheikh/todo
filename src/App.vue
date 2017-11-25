<template>
  <div id="app">
    <task v-on:add-task="addTask"></task>
    <task-list v-bind:todos="todos" v-on:remove-task="removeTask"></task-list>
  </div>
</template>

<script>
import Task from "./components/Task.vue";
import TaskList from "./components/List.vue";

export default {
  name: 'app',
  components: {
    Task,
    TaskList
  },
  data() {
    return {
      todos: []
    };
  },
  methods: {
    addTask: function (task) {
      this.todos.push(task);
    },
    removeTask: function (task) {
      this.todos = this.todos.filter(todo => todo != task);
    }
  }
}
</script>

<style lang="scss">
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}

h1, h2 {
  font-weight: normal;
}

ul {
  list-style-type: none;
  padding: 0;
}

li {
  display: inline-block;
  margin: 0 10px;
}

a {
  color: #42b983;
}
</style>
